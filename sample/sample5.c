#include <ngx_config.h>
#include <ngx_core.h>

void do_list_test(ngx_pool_t *pool);

int nginx_test_main(int agrc,char **argv)
{
    ngx_log_t *log;
    ngx_pool_t *pool;
    ngx_strerror_init();
    ngx_time_init();
    log = ngx_log_init(0);
    pool = ngx_create_pool(1024,log);

    do_list_test(pool);

    return 0;
}
void do_list_test(ngx_pool_t *pool)
{
    int i = 0;
    ngx_list_t *list;
    ngx_list_part_t *part;
    int * elements;

    list = ngx_list_create(pool,5,sizeof(int));

    //添加20个元素
    for (i = 0; i < 7; i++) {
        int * elem;
        elem = ngx_list_push(list);
        if (elem) {
            *elem = i*3;
        }
    }

    //遍历链表方法1
    part = &list->part;
    elements = part->elts;
    printf("next unit\n");
    for (i = 0; ; i++) {
        if (i >= (int)part->nelts) {
            if (part->next == NULL) {
                break;
            }
            part = part->next;
            elements = part->elts;
            i = 0;
            printf("next unit\n");
        }
        printf("[%d] : %d\n",i,elements[i]);
    }
    printf("\n");	
    //遍历链表方法2
    part = &list->part;
    for (part = &list->part; part; part=part->next) {
        ngx_uint_t m = 0;
        int *elem;
        elem = part->elts;
        printf("next unit\n");
        for (m = 0; m < (int)part->nelts; m++) {
            printf("[%d] : %d\n",m,elem[m]);
        }
    }
}
