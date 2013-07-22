#ifndef __RBTREE_H__
#define __RBTREE_H__
typedef struct rbnode_s rbnode_t;
typedef struct rbtree_s rbtree_t;

#define  RBT_RED	0
#define  RBT_BLACK	1

#define rbt_init(T)             \
    (T)->root = &((T)->nil);    \
    (T)->nil.c = RBT_BLACK

struct rbnode_s {
    int		  k;	/*key*/
    int		  c;	/*color*/
    rbnode_t *p;	/*parent*/
    rbnode_t *l;	/*left*/
    rbnode_t *r;	/*right*/
};

struct rbtree_s {
    rbnode_t *root;
    rbnode_t  nil;
};

rbnode_t* rbt_parent(rbtree_t *T,rbnode_t *nd);
rbnode_t* rbt_min(rbtree_t *T,rbnode_t *x);
rbnode_t* rbt_max(rbtree_t *T,rbnode_t * x);
rbnode_t* rbt_successor(rbtree_t *T,rbnode_t *x);
rbnode_t* rbt_predecessor(rbtree_t *T,rbnode_t *x);
rbnode_t* rbt_search(rbtree_t *T,int k);

int rbt_dept(rbtree_t * T);
int rbt_insert(rbtree_t *T,rbnode_t *z);
int rbt_remove(rbtree_t *T,rbnode_t *z);

void rbt_inorder(rbtree_t * T,void (*visit)(rbnode_t *));

#endif