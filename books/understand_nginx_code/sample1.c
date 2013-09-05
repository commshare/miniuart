#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define NGX_CONF_ERROR       (void *) -1
#define NGX_CONF_OK          NULL

#define NGX_LOG_STDERR            0
#define NGX_LOG_EMERG             1
#define NGX_LOG_ALERT             2
#define NGX_LOG_CRIT              3
#define NGX_LOG_ERR               4
#define NGX_LOG_WARN              5
#define NGX_LOG_NOTICE            6
#define NGX_LOG_INFO              7
#define NGX_LOG_DEBUG             8

#define NGX_LOG_DEBUG_CORE        0x010
#define NGX_LOG_DEBUG_ALLOC       0x020
#define NGX_LOG_DEBUG_MUTEX       0x040
#define NGX_LOG_DEBUG_EVENT       0x080
#define NGX_LOG_DEBUG_HTTP        0x100
#define NGX_LOG_DEBUG_MAIL        0x200
#define NGX_LOG_DEBUG_MYSQL       0x400

#define NGX_LOG_DEBUG_FIRST       NGX_LOG_DEBUG_CORE
#define NGX_LOG_DEBUG_LAST        NGX_LOG_DEBUG_MYSQL
#define NGX_LOG_DEBUG_CONNECTION  0x80000000
#define NGX_LOG_DEBUG_ALL         0x7ffffff0

/*base type*/
typedef struct ngx_cycle_s      ngx_cycle_t;
typedef struct ngx_conf_s       ngx_conf_t;
typedef struct ngx_log_s        ngx_log_t;
typedef struct ngx_open_file_s  ngx_open_file_t;
typedef intptr_t ngx_int_t;
typedef uintptr_t               ngx_uint_t;
typedef intptr_t                ngx_flag_t;
typedef uintptr_t               ngx_atomic_int_t;
typedef intptr_t                ngx_atomic_uint_t;
typedef u_char *(*ngx_log_handler_pt) (ngx_log_t *log, u_char *buf, size_t len);

/*string*/
typedef struct {
        size_t      len;
        u_char     *data;
} ngx_str_t;

/*array*/
typedef struct {
        void        *elts;
        ngx_uint_t   nelts;
} ngx_array_t;


/*openfile*/
struct ngx_open_file_s {
        ngx_str_t             name;
};

/*log node*/
struct ngx_log_s {
        ngx_uint_t           log_level;
        ngx_open_file_t     *file;
        ngx_atomic_uint_t    connection;
        ngx_log_handler_pt   handler;
        void                *data;
        char                *action;
        ngx_log_t           *next;
};

/*cycle*/
struct ngx_cycle_s {
        ngx_log_t             new_log;
        ngx_uint_t            log_use_stderr;
};

struct ngx_conf_s {
        ngx_cycle_t          *cycle;
        ngx_array_t          *args;
};

static char * ngx_error_log(ngx_conf_t *cf);
char * ngx_log_set_log(ngx_conf_t *cf, ngx_log_t **head);
static void ngx_log_insert(ngx_log_t *log, ngx_log_t *new_log);
/*stub*/
#define ngx_strcmp(s1, s2)  strcmp((const char *) s1, (const char *) s2)
#define ngx_strstr(s1, s2)  strstr((const char *) s1, (const char *) s2)
#define ngx_strlen(s)       strlen((const char *) s)
#define ngx_strchr(s1, c)   strchr((const char *) s1, (int) c)
#define ngx_string(str)     { sizeof(str) - 1, (u_char *) str }
#define ngx_null_string     { 0, NULL }
#define ngx_pcalloc(y,x)    calloc(1,x)
#define ngx_str_null(str)   (str)->len = 0; (str)->data = NULL

static ngx_open_file_t * ngx_conf_open_file(ngx_cycle_t *cycle, ngx_str_t * name) 
{
        ngx_open_file_t * openfile;
        openfile = (ngx_open_file_t*)malloc(sizeof(ngx_open_file_t));
        openfile->name.len = name->len;
        openfile->name.data = name->data;
        return openfile;
}

static ngx_str_t err_levels[] = {
        ngx_null_string,
        ngx_string("emerg"),
        ngx_string("alert"),
        ngx_string("crit"),
        ngx_string("error"),
        ngx_string("warn"),
        ngx_string("notice"),
        ngx_string("info"),
        ngx_string("debug")
};

static const char *debug_levels[] = {
        "debug_core", "debug_alloc", "debug_mutex", "debug_event",
        "debug_http", "debug_mail", "debug_mysql"
};

int main(int argc,const char * const argv)
{
        ngx_str_t logconf1[] = {ngx_string("error_log"),ngx_string("logs/error.log")};
        ngx_str_t logconf2[] = {ngx_string("error_log"),ngx_string("logs/error.log"),ngx_string("notice")};
        ngx_str_t logconf3[] = {ngx_string("error_log"),ngx_string("logs/error.log"),ngx_string("debug_core")};
        ngx_str_t logconf4[] = {ngx_string("error_log"),ngx_string("logs/debug.log"),ngx_string("debug_core"),ngx_string("debug_mysql")};
        
        /*we add all log*/
        ngx_cycle_t cycle = {0};
        ngx_array_t args = {0};
        ngx_conf_t conf = {&cycle,&args};

        conf.args->elts = logconf1;
        conf.args->nelts = 2;
        ngx_error_log(&conf);

        conf.args->elts = logconf2;
        conf.args->nelts = 3;
        ngx_error_log(&conf);

        conf.args->elts = logconf3;
        conf.args->nelts = 3;
        ngx_error_log(&conf);

        conf.args->elts = logconf4;
        conf.args->nelts = 4;
        ngx_error_log(&conf);
        
        return 0;
}

static char *
ngx_log_set_levels(ngx_conf_t *cf, ngx_log_t *log)
{
    ngx_uint_t   i, n, d, found;
    ngx_str_t   *value;

    if (cf->args->nelts == 2) {
        log->log_level = NGX_LOG_ERR;
        return NGX_CONF_OK;
    }

    value = cf->args->elts;

    for (i = 2; i < cf->args->nelts; i++) {
        found = 0;

        for (n = 1; n <= NGX_LOG_DEBUG; n++) {
            if (ngx_strcmp(value[i].data, err_levels[n].data) == 0) {

                if (log->log_level != 0) {
                    printf("duplicate log level \"%s\"",&value[i]);
                    return NGX_CONF_ERROR;
                }

                log->log_level = n;
                found = 1;
                break;
            }
        }

        for (n = 0, d = NGX_LOG_DEBUG_FIRST; d <= NGX_LOG_DEBUG_LAST; d <<= 1) {
            if (ngx_strcmp(value[i].data, debug_levels[n++]) == 0) {
                if (log->log_level & ~NGX_LOG_DEBUG_ALL) {
                    printf("invalid log level \"%s\"",&value[i]);
                    return NGX_CONF_ERROR;
                }

                log->log_level |= d;
                found = 1;
                break;
            }
        }


        if (!found) {
            printf("invalid log level \"%s\"",&value[i]);
            return NGX_CONF_ERROR;
        }
    }

    if (log->log_level == NGX_LOG_DEBUG) {
        log->log_level = NGX_LOG_DEBUG_ALL;
    }

    return NGX_CONF_OK;
}


static char *
ngx_error_log(ngx_conf_t *cf)
{
    ngx_log_t  *dummy;

    dummy = &cf->cycle->new_log;

    return ngx_log_set_log(cf, &dummy);
}


char *
ngx_log_set_log(ngx_conf_t *cf, ngx_log_t **head)
{
    ngx_log_t  *new_log;
    ngx_str_t  *value, name;

    if (*head != NULL && (*head)->log_level == 0) {
        new_log = *head;

    } else {

        new_log = ngx_pcalloc(cf->pool, sizeof(ngx_log_t));
        if (new_log == NULL) {
            return NGX_CONF_ERROR;
        }

        if (*head == NULL) {
            *head = new_log;
        }
    }

    value = cf->args->elts;

    if (ngx_strcmp(value[1].data, "stderr") == 0) {
        ngx_str_null(&name);
        cf->cycle->log_use_stderr = 1;

    } else {
        name = value[1];
    }

    new_log->file = ngx_conf_open_file(cf->cycle, &name);
    if (new_log->file == NULL) {
        return NGX_CONF_ERROR;
    }

    if (ngx_log_set_levels(cf, new_log) != NGX_CONF_OK) {
        return NGX_CONF_ERROR;
    }

    if (*head != new_log) {
        ngx_log_insert(*head, new_log);
    }

    return NGX_CONF_OK;
}


static void
ngx_log_insert(ngx_log_t *log, ngx_log_t *new_log)
{
    ngx_log_t  tmp;

    if (new_log->log_level > log->log_level) {

        /*
         * list head address is permanent, insert new log after
         * head and swap its contents with head
         */

        tmp = *log;
        *log = *new_log;
        *new_log = tmp;

        log->next = new_log;
        return;
    }

    while (log->next) {
        if (new_log->log_level > log->next->log_level) {
            new_log->next = log->next;
            log->next = new_log;
            return;
        }

        log = log->next;
    }

    log->next = new_log;
}
