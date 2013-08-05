#include <ngx_config.h>
#include <ngx_core.h>

void clean_handler(void *data);
void do_mem_pool_test(ngx_log_t *elog);

int nginx_test_main(int agrc,char **argv)
{
        ngx_log_t *log;

        ngx_strerror_init();
        ngx_time_init();
        log = ngx_log_init(0);

        do_mem_pool_test(log);

        return 0;
}

void clean_handler(void *data)
{
        char * str = (char *)data;
        printf("%s",str);
        return;
}

void do_mem_pool_test(ngx_log_t *elog)
{
        char * p1, *p2;
        ngx_pool_t *pool;
        ngx_pool_cleanup_t * cln;

        //创建一个内存池,查看内存池剩余
        pool = ngx_create_pool(1024,elog);
        printf("create pool, memory remain: %d\n",pool->d.end - pool->d.last);

        //从池里分配空间,查看剩余
        p1 = ngx_palloc(pool,512);
        printf("alloc 512 byte,remain: %d\n",pool->d.end - pool->d.last);

        //从池里分配空间,查看剩余
        p2 = ngx_palloc(pool,51);
        printf("alloc 51 byte,remain: %d\n",pool->d.end - pool->d.last);

        //注册内存池回收回调
        cln = ngx_pool_cleanup_add(pool,32);
        strcpy(cln->data,"hello go die!\n");
        cln->handler = clean_handler;

        //销毁内存池将会回调
        ngx_destroy_pool(pool);

        //创建一个内存池,查看内存池剩余
        pool = ngx_create_pool(1024,elog);
        printf("create pool, memory remain: %d\n",pool->d.end - pool->d.last);

        //从池里分配空间,查看剩余
        p1 = ngx_palloc(pool,512);
        printf("alloc 512 byte,remain: %d\n",pool->d.end - pool->d.last);

        //从池里分配空间(当前剩余不足以满足用户需求),查看下一块的剩余
        p2 = ngx_palloc(pool,512);
        printf("alloc 512 byte,remain: %d\n",pool->d.next->d.end - pool->d.next->d.last);

        return ;
}
