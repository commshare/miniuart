#include <ngx_config.h>
#include <ngx_core.h>

#define KB  (1024)
#define MB  ((1024)*KB)

typedef struct _rbtree_node_s{
    ngx_rbtree_node_t node;
    ngx_int_t value;
}rbtree_node_t;

static void do_test_slab(ngx_log_t * log);
static void do_test_radix(ngx_log_t * log);
static void do_test_hash(ngx_log_t * log);
static void do_test_regex(ngx_log_t * log);

void ngx_test_case(ngx_cycle_t *cycle)
{
    do_test_slab(cycle->log);
    do_test_radix(cycle->log);
    do_test_hash(cycle->log);
    do_test_regex(cycle->log);
}

static int _ngx_dns_strcmp(const void *one,const void *two)
{
    ngx_hash_key_t  *first, *second;
    first = (ngx_hash_key_t *) one;
    second = (ngx_hash_key_t *) two;
    return strncmp(first->key.data, second->key.data,first->key.len);
}

static void do_test_hash(ngx_log_t * log) 
{
    ngx_pool_t * pool;
    ngx_hash_keys_arrays_t ha;
    ngx_int_t v[6] = {16,32,64,128,256,512}; /*must be aligned by 4*/
    ngx_int_t i,value;
    ngx_hash_init_t hash;
    ngx_hash_combined_t cmb;
    ngx_str_t test;
    ngx_uint_t key;

    /*key/value*/
    ngx_str_t keys[] = {
        ngx_string("www.test1.com"), /*hash*/
        ngx_string("*.test2.com"),   /*wildcard hash head*/
        ngx_string("*.test2.net"),
        ngx_string("*.test3.com"),
        ngx_string("www.test3.*"),   /*wildcard hash */
        ngx_string("mail.test3.*"),
    };

    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE,log);
    ha.temp_pool = ha.pool = pool;
    ngx_hash_keys_array_init(&ha,NGX_HASH_LARGE);

    /*add keys*/
    for (i = 0;i < 6;i++) {
        ngx_str_t k;
        k.len = keys[i].len;
        k.data = ngx_pstrdup(pool,&keys[i]);
        ngx_hash_add_key(&ha,&k,(void *)v[i],1);
    }
    
    hash.key = ngx_hash_key;
    hash.pool = pool;
    hash.max_size = 1024;
    hash.bucket_size = 76;
    hash.name = "test_names_hash";
    ha.temp_pool = ha.pool = pool;

    /*create hash*/
    if (ha.keys.nelts) {
        hash.hash = &cmb.hash;
        hash.temp_pool = NULL;
        ngx_hash_init(&hash, ha.keys.elts, ha.keys.nelts);
    }

    /*create wildcard hash head*/
    if (ha.dns_wc_head.nelts) {
        ngx_qsort(ha.dns_wc_head.elts, (size_t) ha.dns_wc_head.nelts,
            sizeof(ngx_hash_key_t), _ngx_dns_strcmp);
        hash.hash = NULL;
        hash.temp_pool = ha.temp_pool;
        ngx_hash_wildcard_init(&hash,ha.dns_wc_head.elts,ha.dns_wc_head.nelts);
        cmb.wc_head = (ngx_hash_wildcard_t *) hash.hash;
    }

    /*create wildcard hash tail*/
    if (ha.dns_wc_tail.nelts) {
        ngx_qsort(ha.dns_wc_tail.elts, (size_t) ha.dns_wc_tail.nelts,
            sizeof(ngx_hash_key_t), _ngx_dns_strcmp);
        hash.hash = NULL;
        hash.temp_pool = ha.temp_pool;
        ngx_hash_wildcard_init(&hash, ha.dns_wc_tail.elts,ha.dns_wc_tail.nelts);
        cmb.wc_tail = (ngx_hash_wildcard_t *) hash.hash;
    }
    
    /*search www.test1.com*/
    ngx_str_set(&test,"www.test1.com");
    key = ngx_hash_key(test.data,test.len);
    value = (ngx_int_t)ngx_hash_find_combined(&cmb,key,test.data,test.len);
    printf("value: %d\n",value);

    /*search www.test2.com*/
    ngx_str_set(&test,"www.test2.com");
    key = ngx_hash_key(test.data,test.len);
    value = (ngx_int_t)ngx_hash_find_combined(&cmb,key,test.data,test.len);
    printf("value: %d\n",value);

    /*search mail.test2.com*/
    ngx_str_set(&test,"mail.test2.com");
    key = ngx_hash_key(test.data,test.len);
    value = (ngx_int_t)ngx_hash_find_combined(&cmb,key,test.data,test.len);
    printf("value: %d\n",value);

    /*search mail.test3.cn*/
    ngx_str_set(&test,"mail.test3.cn");
    key = ngx_hash_key(test.data,test.len);
    value = (ngx_int_t)ngx_hash_find_combined(&cmb,key,test.data,test.len);
    printf("value: %d\n",value);

    /*search mail.test3.org*/
    ngx_str_set(&test,"mail.test3.com");
    key = ngx_hash_key(test.data,test.len);
    value = (ngx_int_t)ngx_hash_find_combined(&cmb,key,test.data,test.len);
    printf("value: %d\n",value);

    ngx_destroy_pool(ha.temp_pool);
    return;
}

static void do_test_radix(ngx_log_t * log)
{
        ngx_radix_tree_t *tree;
        ngx_pool_t *pool;
        u_char * p;

        /*create memory pool*/
        pool = ngx_create_pool(1024,log);
        tree = ngx_radix_tree_create(pool,0);

        /*32 bit*/
        /**************************************************
         *insert 
         *C0 00 00 00 =>11000000 00000000 00000000 00000000
         *40 00 00 00 =>01000000 00000000 00000000 00000000
         *80 00 00 00 =>10000000 00000000 00000000 00000000
         * 
         *result
         *     r
         *   0   1
         *    1 0 1
         **************************************************/
        ngx_radix32tree_insert(tree,0xC0000000,0xE0000000,(uintptr_t)"test1");
        ngx_radix32tree_insert(tree,0x40000000,0xE0000000,(uintptr_t)"test2");
        ngx_radix32tree_insert(tree,0x80000000,0xE0000000,(uintptr_t)"test3");

        /*find*/
        p = (u_char *)ngx_radix32tree_find(tree,0xC0000000);
        printf("%s\n",p);

        p = (u_char *)ngx_radix32tree_find(tree,0x40000000);
        printf("%s\n",p);

        p = (u_char *)ngx_radix32tree_find(tree,0x80000000);
        printf("%s\n",p);

        return;
}


void _rbtree_insert(ngx_rbtree_node_t *temp, ngx_rbtree_node_t *node,
    ngx_rbtree_node_t *sentinel)
{
    ngx_rbtree_node_t  **p;
    rbtree_node_t *nd;

    for ( ;; ) {
        if (node->key < temp->key) {
            p = &temp->left;
        } else {
            p = &temp->right;
        }
        if (*p == sentinel) {
            /*insert here*/
            nd = (rbtree_node_t*)node;
            printf("insert [%d]:%c\n",nd->node.key,(char)nd->value);
            break;
        }
        temp = *p;
    }
    *p = node;
    node->parent = temp;
    node->left = sentinel;
    node->right = sentinel;
    ngx_rbt_red(node);
}

static void do_test_rbtree(ngx_log_t * log)
{
    ngx_rbtree_t rbtree;
    ngx_rbtree_node_t sentinel,*node;
    rbtree_node_t *rbnode;
    ngx_pool_t *pool;
    ngx_int_t i;
    
    /*create memory pool*/
    pool = ngx_create_pool(1024,log);

    /*init ngx_rbtree*/
    ngx_rbtree_init(&rbtree, &sentinel,_rbtree_insert);

    /*insert*/
    for (i = 0;i < 5;i++) {
        rbnode = ngx_palloc(pool,sizeof(rbtree_node_t));
        rbnode->value = 'A'+i;
        rbnode->node.key = i;
        ngx_rbtree_insert(&rbtree,&rbnode->node);
    }

    /*find key 4*/
    for (node = rbtree.root;node != rbtree.sentinel;) {
        if (node->key > 4) {
            node = node->left;
        } else if (node->key < 4) {
            node = node->right;
        } else {
            break;
        }
    }
    /*find*/
    if (node != rbtree.sentinel) {
        rbnode = (rbtree_node_t *)node;
        printf("find [%d]:%c\n",node->key,(char)rbnode->value);
    } else {
        printf("node find\n");
    }

    /*delete data*/
    while (rbtree.root != rbtree.sentinel) {
        node = ngx_rbtree_min(rbtree.root,&sentinel);
        rbnode = (rbtree_node_t*)node;
        printf("remove [%d]:%c\n",node->key,(char)rbnode->value);
        ngx_rbtree_delete(&rbtree,node);
    }

    ngx_destroy_pool(pool);
    return ;
}

static void do_test_slab(ngx_log_t * log)
{
    ngx_shm_t shm;
    ngx_slab_pool_t  *sp;
    void *p1,*p2,*p3;
    u_char * file;

    ngx_memzero(&shm,sizeof(ngx_shm_t));

    shm.size = 10*MB; /*10MB*/
    ngx_str_set(&shm.name,"hello_zone");
    shm.log = log;
    ngx_shm_alloc(&shm);

    sp = (ngx_slab_pool_t *) shm.addr;
    if (shm.exists) {
        return ;
    }

    sp->end = shm.addr + shm.size;
    sp->min_shift = 3;
    sp->addr = shm.addr;
   
#if (NGX_HAVE_ATOMIC_OPS)
    file = NULL;
#else
    file = ngx_pnalloc(cycle->pool, cycle->lock_file.len + zn->shm.name.len);
    if (file == NULL) {
        return NGX_ERROR;
    }
    (void) ngx_sprintf(file, "%V%V%Z", &cycle->lock_file, &zn->shm.name);

#endif
    /*create mutex*/
    ngx_shmtx_create(&sp->mutex, &sp->lock,file);

    /*init slab*/
    ngx_slab_init(sp);

    p1 = ngx_slab_alloc(sp,5*MB);
    p2 = ngx_slab_alloc(sp,1*MB);
    ngx_slab_free(sp,p1);
    ngx_slab_free(sp,p2);
    p3 = ngx_slab_alloc(sp,6*MB);
    ngx_slab_free(sp,p3);

    p1 = ngx_slab_alloc(sp,1);

    return ;
}

static ngx_pool_t *ngx_regex_pool;
static void * (ngx_libc_cdecl *ngx_regex_malloc_old)(size_t size);
static void  (ngx_libc_cdecl *ngx_regex_free_old)(void *p);
static void * ngx_libc_cdecl ngx_regex_malloc_new(size_t size) {return (void*)ngx_palloc(ngx_regex_pool,size);}
static void  ngx_libc_cdecl ngx_regex_free_new(void *p){return;}

static void do_test_regex(ngx_log_t * log)
{
    ngx_regex_compile_t   rc;
    u_char  errstr[NGX_MAX_CONF_ERRSTR];
    ngx_pool_t *pool;
    ngx_int_t  r;
    ngx_str_t url[3];
    int captures[2],i;

    /*create memory pool*/
    pool = ngx_create_pool(1024,log);

    ngx_regex_pool = pool;
    ngx_regex_malloc_old = pcre_malloc;
    ngx_regex_free_old = pcre_free;
    ngx_memzero(&rc, sizeof(ngx_regex_compile_t));

    rc.pool = pool;
    rc.err.len = NGX_MAX_CONF_ERRSTR;
    rc.err.data = errstr;
    rc.options = NGX_REGEX_CASELESS;

    ngx_str_set(&rc.pattern,"\\.php$");
    if (ngx_regex_compile(&rc) != NGX_OK) {
        printf("ngx_regex_compile() failed!");
        exit(-3);
    }

    ngx_str_set(&url[0],"http://www.test.com/");
    ngx_str_set(&url[1],"http://www.test.com/index.php");
    ngx_str_set(&url[2],"http://www.test.com/test.php/test.html");

    for (i = 0;i < sizeof(url)/sizeof(url[0]);i++) {
            r = ngx_regex_exec(rc.regex, &url[i],captures,2);
            if (r == NGX_REGEX_NO_MATCHED) {
                    printf("[-1][%s]:not match\n",url[i].data);
            } else {
                    printf("[%2d][%s]:match\n",r,url[i].data);
            }
    }

    pcre_malloc = ngx_regex_malloc_old;
    pcre_free = ngx_regex_free_old;
    ngx_destroy_pool(pool);
        
    return ;
}