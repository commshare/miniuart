typedef struct node_s node_t;
typedef struct tree_s tree_t;

#define NIL 0
#define init(x) x->l=x->r=x->p=NIL

struct node_s {
	int		 k;	/*key*/
	node_t	*p;	/*parent*/
	node_t	*l;	/*left*/
	node_t	*r;	/*right*/
};

struct tree_s {
	node_t * root;
};

node_t * search(tree_t *T,int k) 
{
	node_t * x;
	x = T->root;
	while (x != NIL) {
		if (k == x->k) {
			break;
		}
		if (k < x->k) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	return x;
}

node_t * max(node_t * x) 
{
	while (x->r != NIL) {
		x = x->r;
	}
	return x;
}

node_t * min(node_t *x) 
{
	while (x->l != NIL) {
		x = x->l;
	}
	return x;
}

node_t * successor(node_t *x)
{
	node_t *y;
	if (x->r != NIL) {
		y = min(x->r);
	} else {
		y = x->p;
		while ((y != NIL) && (y->r == x)) {
			x = y;
			y = x->p;
		}
	}
	return y;
}

node_t * predecessor(node_t *x)
{
	node_t *y;
	if (x->l != NIL) {
		y = max(x->l);
	} else {
		y = x->p;
		while ((y != NIL) && (y->l == x)) {
			x = y;
			y = x->p;
		}
	}
	return y;
}

void inorder(tree_t * T,void (*visit)(node_t *))
{
	node_t *x;
	x = T->root;
	if (x == NIL) {
		x = min(x);
		while (x != NIL) {
			visit(x);
			x = successor(x);
		}
	}
	return ;
}

int insert(tree_t *T,node_t *z)
{
	node_t *x,*y;
	x = T->root;
	y = x;
	while (x != NIL) {
		y = x;
		if (z->k == x->k) {
			return 1;
		}
		if (z->k < x->k) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	init(z);
	if (y == NIL) {
		T->root = z;
	} else {
		if (z->k < y->k) {
			y->l = z;
		} else {
			y->r = z;
		}
		z->p = y;
	}
	return 0;
}

void _transplant(tree_t *T,node_t *u,node_t *v) 
{
	if (u->p == NIL) {
		T->root = v;
	} else {
		if (u->p->l == u) {
			u->p->l = v;
		} else {
			u->p->r = v;
		}	
	}
	if (v != NIL) {
		v->p = u->p;
	}
	return ;
}

int remove(tree_t *T,node_t *z)
{
	do {
		node_t * y;
		if (z->r == NIL) {
			_transplant(T,z,z->l);
			break;
		}
		y = min(z->r);
		if (y != z->r) {
			_transplant(T,y,y->r);
			y->r = z->r;
			y->r->p = y;
		}
		_transplant(T,z,y);
		y->l = z->l;
		if (z->l != NIL) {
			z->l->p = y;
		}
	} while (0);
	return 0;
}