#include <ngx_config.h>
#include <ngx_core.h>

int nginx_test_main(int agrc,char **argv)
{
    ngx_log_t *log;
    
    ngx_strerror_init();
    ngx_time_init();
    
    log = ngx_log_init(0);
 
    /*log to file*/
    ngx_log_error(NGX_LOG_WARN,log,14,"log to file");

    /*log to console*/ 
    ngx_log_stderr(3,"hello stderr:name:%s","test");
    
    return 0;
}
