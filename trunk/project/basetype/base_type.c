/*******************************************************************************
*File name : base_dtypes.c
*
*Description:
*
*Author:
*   nie@song.ah.cn
*
*Date:
*   2013-4-17 15:10
*
*All Right Reserved (c) 2010 - 2012
*******************************************************************************/
#include "base_type.h"
#include <string.h>

struct bitset_data {
        unsigned int size;
        unsigned int cnt;
        void *(*balloc)(size_t );
        void (*bfree)(void *);
        unsigned char data[1];
};

#define _base_align(d,a)         (((d)+((a)-1))&~((a)-1))

/*list implement*/
int base_list_init(base_list_t * l)
{
        l->next = l;
        l->prev = l;

        return 0;
}

int base_list_insert_h(base_list_t * l,base_link * n)
{
        n->next = l->next;
        n->prev = l;
        n->next->prev = n;
        n->prev->next = n;

        return 0;
}

int base_list_insert_t(base_list_t * l,base_link * n)
{
        n->next = l;
        n->prev = l->prev;
        n->next->prev = n;
        n->prev->next = n;

        return 0;
}

int base_list_remove(base_link * n)
{
        n->next->prev = n->prev;
        n->prev->next = n->next;
        return 0;
}

int base_list_num(base_list_t * l)
{
        int i = 0;
        base_link * it;
        it = l->next;
        for (; it != l; it = it->next) {
                i++;
        }
        return i;
}

base_link * base_list_find(base_list_t *l,base_compare_proc cb,void * pa)
{
        base_link * it,*found = 0;
        it = l->next;
        for (; it != l; it = it->next) {
                if (!cb(it,pa)) {
                        found = it;
                        break;
                }
        }
        return found;
}

/*queue implement*/
int base_queue_init(base_queue_t * q)
{
        q->prev = q;
        q->next = q;

        return 0;
}

int base_queue_push(base_queue_t * q,base_link *n)
{
        n->next = q;
        n->prev = q->prev;
        n->next->prev = n;
        n->prev->next = n;

        return 0;
}

base_link * base_queue_pop(base_queue_t * q)
{
        if (q->next != q) {
                base_link * n;
                n = q->next;
                n->next->prev = n->prev;
                n->prev->next = n->next;
                n->next = 0;
                n->prev = 0;

                return n;
        }
        return 0;
}

base_link * base_queue_front(base_queue_t * q)
{
        if (q->next != q->prev) {
                return q->next;
        }
        return 0;
}

int base_queue_length(base_queue_t * q)
{
        int i = 0;
        base_link * it;
        it = q->next;
        for (; it != q; it = it->next) {
                i++;
        }
        return i;
}

/*stack implement*/
int base_stack_init(base_stack_t *st)
{
        st->next = st;
        st->prev = st;

        return 0;
}

int base_stack_push(base_stack_t *st,base_link *n)
{
        n->next = st->next;
        n->prev = st;
        n->next->prev = n;
        n->prev->next = n;

        return 0;
}


base_link * base_stack_pop(base_stack_t *st)
{
        if (st->next != st) {
                base_link * n;
                n = st->next;
                n->next->prev = n->prev;
                n->prev->next = n->next;

                return n;
        }
        return 0;
}

int base_stack_dept(base_stack_t *st)
{
        int i = 0;
        base_link * it;
        it = st->next;
        for (; it != st; it = it->next) {
                i++;
        }
        return i;
}

/*bit set implement*/
base_bitset_t *base_bitset_create(unsigned int size,unsigned char f,
        void *(*alloc)(unsigned int ),void (*fr)(void *))
{
        int bitsize;
        struct bitset_data * set;

        bitsize = (_base_align(size,8)) >> 3;
        set = (struct bitset_data *)
                alloc(bitsize + sizeof(struct bitset_data));

        if (set) {
                base_bitset_reset((base_bitset_t *)set,f);
                return (base_bitset_t *)set;
        }
        return 0;
}

int base_bitset_destroy(base_bitset_t * bitset)
{
        struct bitset_data *set = (struct bitset_data *)bitset;
        if (set) {
                set->bfree(set);
        }
        return 0;
}

int base_bitset_set(base_bitset_t * bitset,unsigned int of,unsigned char f)
{
        int pos,i;
        unsigned char byte;
        struct bitset_data *set = (struct bitset_data *)bitset;

        pos = of%8;
        i = of/8;

        byte = set->data[i];
        if (((byte >> pos) & 1) != f) {
                if (f) {
                        set->data[i] |= (1 << pos);
                        set->cnt++;
                } else {
                        set->data[i] &= (~(1 << pos));
                        set->cnt--;
                }
        }
        return f;
}

int base_bitset_test(base_bitset_t * bitset,unsigned int of)
{
        int pos,i;
        struct bitset_data *set = (struct bitset_data *)bitset;

        pos = of%8;
        i = of/8;

        return (set->data[i] >> pos) & 1;
}

int base_bitset_count(base_bitset_t * bitset)
{
        struct bitset_data *set = (struct bitset_data *)bitset;
        return set->cnt;
}

int base_bitset_size(base_bitset_t * bitset)
{
        struct bitset_data *set = (struct bitset_data *)bitset;
        return set->size;
}

int base_bitset_reset(base_bitset_t * bitset,unsigned char f)
{
        int bitsize;
        struct bitset_data *set = (struct bitset_data *)bitset;

        bitsize = (_base_align(set->size,8)) >> 3;
        if (f) {
                set->cnt = set->size;
                memset(set->data,0xff,bitsize);
        } else {
                set->cnt = 0;
                memset(set->data,0,bitsize);
        }
        return 0;
}
