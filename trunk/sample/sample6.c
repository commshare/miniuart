#include <ngx_config.h>
#include <ngx_core.h>

void do_queue_test(ngx_pool_t *pool);

int nginx_test_main(int agrc,char **argv)
{
    ngx_log_t *log;
    ngx_pool_t *pool;
    ngx_strerror_init();
    ngx_time_init();
    log = ngx_log_init(0);

    //创建一个内存池
    pool = ngx_create_pool(1024,log);
    do_queue_test(pool);

    return 0;
}

struct nodeinfo {
    int body;
    ngx_queue_t link;
};

/*求队列的长度*/
int get_queue_len(ngx_queue_t *h) 
{
    ngx_queue_t  *it;
    int len = 0;

    it = ngx_queue_head(h);
    while (it != ngx_queue_sentinel(h)) {
        len++;
        it = ngx_queue_next(it);
    }    
    return len;
}

ngx_int_t my_sort(const ngx_queue_t * q1, const ngx_queue_t * q2)
{
    struct nodeinfo *nd1,*nd2;
    nd1 = ngx_queue_data(q1,struct nodeinfo,link);
    nd2 = ngx_queue_data(q2,struct nodeinfo,link);
    return (nd1->body - nd2->body);
}

void do_queue_test(ngx_pool_t *pool)
{
    ngx_queue_t queue;
    int i;
    struct nodeinfo * nd;
    ngx_queue_t  *it;
    
    //初始化队列
    ngx_queue_init(&queue);
    if (ngx_queue_empty(&queue)) {
        printf("the queue is empty!\n");
    } 

    //添加5个节点
    for (i = 0;i < 5;i++) {
        nd = ngx_palloc(pool,sizeof(struct nodeinfo));
        nd->body = rand()%20;
        printf("add node:%d!\n",nd->body);
        ngx_queue_insert_head(&queue,&nd->link);
    }
    
    printf("queue len:%d\n",get_queue_len(&queue));
    
    //排序
    ngx_queue_sort(&queue,my_sort);
    
    for (i = 0;i < 3;i++) {
        it = ngx_queue_head(&queue);
        ngx_queue_remove(it);
        nd = ngx_queue_data(it,struct nodeinfo,link);
        printf("the queue remove: %d\n",nd->body);
    }
        
    //打印剩余节点
    it = ngx_queue_head(&queue);
    while (it!= ngx_queue_sentinel(&queue)) {
        nd = ngx_queue_data(it,struct nodeinfo,link);
        printf("remain: %d\n",nd->body);
        it = ngx_queue_next(it);
    }
}
