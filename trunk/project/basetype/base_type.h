#ifndef __BASE_DTYPES_H__
#define __BASE_DTYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#define struct_entry(p,t,m)                                 \
    ((t *)((char *)(p)-(unsigned long)(&((t *)0)->m))) 
   
/* NOTE: we use chunk (size in BYTE) like this 
alloc:
        struct mem_chunk_s * chunk;
        chunk = (struct mem_chunk_s*)malloc(sizeof(struct mem_chunk_s)+size);
        chunk->sz = size;
usage:  
        chunk->sz
        chunk->buf
free:
        free(chunk)
*/
struct mem_chunk_s {
        int    sz;
        char   buf[1];
};

struct link_s {
        struct link_s * prev;
        struct link_s * next;
};

struct base_bitset_s {
        char data[1];
};

typedef struct link_s base_link;
typedef struct link_s base_list_t;
typedef struct link_s base_queue_t;
typedef struct link_s base_stack_t;
typedef struct base_bitset_s base_bitset_t;
typedef struct mem_chunk_s mem_chunk_t;
typedef void base_handle_t;

typedef int (*base_compare_proc)(base_link *link,void *data);

/*list interface*/
int base_list_init(base_list_t * l);
int base_list_insert_h(base_list_t * l,base_link * n);
int base_list_insert_t(base_list_t * l,base_link * n);
int base_list_remove(base_link * n);
int base_list_num(base_list_t * l);
base_link * base_list_find(base_list_t *l,base_compare_proc,void *);

/*queue interface*/
int base_queue_init(base_queue_t * q);
int base_queue_push(base_queue_t * q,base_link *n);
base_link * base_queue_pop(base_queue_t * q);
base_link * base_queue_front(base_queue_t * q);
int base_queue_length(base_queue_t * q);

/*stack interface*/
int base_stack_init(base_stack_t *st);
int base_stack_push(base_stack_t *st,base_link *n);
base_link * base_stack_pop(base_stack_t *st);
int base_stack_dept(base_stack_t *st);

/*bit set interface*/
base_bitset_t * base_bitset_create(unsigned int size,unsigned char f,void *(*alloc)(unsigned int sz),void (*fr)(void * p));
int base_bitset_destroy(base_bitset_t * bitset);
int base_bitset_set(base_bitset_t * bitset,unsigned int of,unsigned char f);
int base_bitset_reset(base_bitset_t * bitset,unsigned char f);
int base_bitset_test(base_bitset_t * bitset,unsigned int of);
int base_bitset_count(base_bitset_t * bitset);
int base_bitset_size(base_bitset_t * bitset);

#ifdef __cplusplus
}
#endif

#endif
