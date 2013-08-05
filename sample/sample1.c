#include <ngx_config.h>
#include <ngx_core.h>
#include <nginx.h>

int nginx_test_main(int agrc,char **argv)
{
        ngx_strerror_init();
        return 0;
}
