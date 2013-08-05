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

        //����һ���ڴ��,�鿴�ڴ��ʣ��
        pool = ngx_create_pool(1024,elog);
        printf("create pool, memory remain: %d\n",pool->d.end - pool->d.last);

        //�ӳ������ռ�,�鿴ʣ��
        p1 = ngx_palloc(pool,512);
        printf("alloc 512 byte,remain: %d\n",pool->d.end - pool->d.last);

        //�ӳ������ռ�,�鿴ʣ��
        p2 = ngx_palloc(pool,51);
        printf("alloc 51 byte,remain: %d\n",pool->d.end - pool->d.last);

        //ע���ڴ�ػ��ջص�
        cln = ngx_pool_cleanup_add(pool,32);
        strcpy(cln->data,"hello go die!\n");
        cln->handler = clean_handler;

        //�����ڴ�ؽ���ص�
        ngx_destroy_pool(pool);

        //����һ���ڴ��,�鿴�ڴ��ʣ��
        pool = ngx_create_pool(1024,elog);
        printf("create pool, memory remain: %d\n",pool->d.end - pool->d.last);

        //�ӳ������ռ�,�鿴ʣ��
        p1 = ngx_palloc(pool,512);
        printf("alloc 512 byte,remain: %d\n",pool->d.end - pool->d.last);

        //�ӳ������ռ�(��ǰʣ�಻���������û�����),�鿴��һ���ʣ��
        p2 = ngx_palloc(pool,512);
        printf("alloc 512 byte,remain: %d\n",pool->d.next->d.end - pool->d.next->d.last);

        return ;
}
