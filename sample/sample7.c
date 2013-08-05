#include <ngx_config.h>
#include <ngx_core.h>
#include <nginx.h>

/**********************
 * test radix tree
 **********************/
int nginx_test_main(int agrc,char **argv)
{
        ngx_radix_tree_t *tree;
        ngx_log_t *log;
        ngx_pool_t *pool;
        char * p;
        
        ngx_strerror_init();
        ngx_time_init();
        log = ngx_log_init(0);

        //create memory pool
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
        p = (char *)ngx_radix32tree_find(tree,0xC0000000);
        printf("%s\n",p);

        p = (char *)ngx_radix32tree_find(tree,0x40000000);
        printf("%s\n",p);

        p = (char *)ngx_radix32tree_find(tree,0x80000000);
        printf("%s\n",p);

        return 0;
}