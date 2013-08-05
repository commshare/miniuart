#include <ngx_config.h>
#include <ngx_core.h>

void do_array_test(ngx_pool_t *pool);

int nginx_test_main(int agrc,char **argv)
{
    ngx_log_t *log;
    ngx_pool_t *pool;
    ngx_strerror_init();
    ngx_time_init();
    log = ngx_log_init(0);


    //����һ���ڴ��
    pool = ngx_create_pool(1024,log);

    do_array_test(pool);

    return 0;
}

void do_array_test(ngx_pool_t *pool)
{
    ngx_array_t * array1;
    int *element;
    int i = 0;

    //����һ��10Ԫ�ص�int����
    array1 = ngx_array_create(pool,10,sizeof(int));
    //���20��Ԫ��
    for (i = 0; i < 20; i++) {
        int * elem;
        elem = ngx_array_push(array1);
        if (elem) {
            *elem = i*2;
        }
    }
    //��������
    element = (int *)array1->elts;
    for (i = 0; i < (int)array1->nelts; i++) {
        printf("[%d] : %d\n",i,element[i]);
    }
}
