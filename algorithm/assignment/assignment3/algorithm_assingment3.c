#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* left;
	struct node* right;
	struct node* parent;
	int height;
	int key;
} node;

node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	p->height = 0;
	p->key = NULL;

	return p;
}
int isExternal(node* p) {
	return(p->left == NULL && p->right == NULL);
}
int isInternal(node* p) {
	return(p->left != NULL || p->right != NULL);
}
int isRoot(node* p) {
	return(p->parent == NULL);
}
void putnode(node* p) {
	free(p);	
}
node* treeSearch(node* v, int k) {
	if (isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key) {
		return treeSearch(v->left, k);
	}
	else
		return treeSearch(v->right, k);
}
void expandExternal(node* w, node* root) {
	node* a = getnode();
	node* b = getnode();
	w->right = a;
	a->parent = w;
	w->left = b;
	b->parent = w;
	if (w != root) {
		node* parent;
		node* cursor = root;
		while (1) {
			if (cursor->left->key == w->key || cursor->right->key == w->key) {
				parent = cursor;
				break;
			}
			else if (cursor->key > w->key) {
				cursor = cursor->left;
			}
			else
				cursor = cursor->right;
		}
		w->parent = parent;
	}
}
void fixHeight(node* w) {
	if (w!=NULL) {
		if (w->left->height > w->right->height) {
			w->height = w->left->height + 1;
		}
		else
			w->height = w->right->height + 1;
		fixHeight(w->parent);
	}

	return;
}
node* restructure(node** x, node** y, node** z) {
	node* a;
	node* b;
	node* c;
	node* T0 = NULL;
	node* T1 = NULL;
	node* T2 = NULL;
	node* T3 = NULL;

	// 여기서 x, y, z를 직접 업데이트
	if ((*x)->key > (*y)->key && (*x)->key > (*z)->key) {
		c = *x;
		if ((*y)->key > (*z)->key) {
			b = *y;
			a = *z;
		}
		else {
			a = *y;
			b = *z;
		}
	}
	else if ((*y)->key > (*x)->key && (*y)->key > (*z)->key) {
		c = *y;
		if ((*x)->key > (*z)->key) {
			b = *x;
			a = *z;
		}
		else {
			a = *x;
			b = *z;
		}
	}
	else {
		c = *z;
		if ((*x)->key > (*y)->key) {
			b = *x;
			a = *y;
		}
		else {
			b = *y;
			a = *x;
		}
	}
	if (a == *z && b== *y && c == *x) {
		T0 = a->left;
		T1 = b->left;
		T2 = c->left;
		T3 = c->right;
	}
	else if (a == *x && b == *y && c == *z) {
		T0 = a->left;
		T1 = a -> right;
		T2 = b->right;
		T3 = c->right;
	}
	else if (a == *z && b == *x && c == *y) {
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	else if (a == *y && b == *x && c == *z) {
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	if (!isRoot(*z) && (*z)->parent->left == *z) {
		(*z)->parent -> left = b;
	}
	else if (!isRoot(*z) && (*z)->parent->right == *z) {
		(*z)->parent->right = b;
	}
	b ->parent = (*z)->parent;
	a->left = T0;
	a->right = T1;
	T0->parent = a;
	T1 ->parent = a;
	c->left = T2;
	c->right = T3;
	T2->parent = c;
	T3->parent = c;
	b->left = a;
	b->right = c;
	a->parent = b;
	c->parent = b;
}

void searchAndFixAfterInsertion(node* w) {
	node* z=w;
	node* y=NULL;
	node* x=NULL;
	int flag = 0;
	while (!isRoot(z)) {
		z = z->parent;
		if (z->left->height > z->right->height) {
			if (z->left->height - z->right->height > 1) {
				flag++;
				y = z->left;
				break;
			}
		}
		else {
			if (z->right->height - z->left->height > 1) {
				flag++;
				y = z->right;
				break;
			}
		}
	}
	if (flag == 0)
		return;
	if (y->left->height > y->right->height) {
		x = y->left;
	}
	else
		x = y->right;
	restructure(&x, &y, &z);
	return;
}
void fixReverse
node* insertItem(node* root, int k) {
	node* w = treeSearch(root, k);
	if (isInternal(w))
		return;
	else {
		w->key = k;
		expandExternal(w,root);
		fixHeight(w);
		searchAndFixAfterInsertion(w);
		fixReverseHeight(root);
		while (!isRoot(w)) {
			w = w->parent;
		}
		return w;
	}
}
int findElement(node* root, int k) {
	node* w = treeSearch(root, k);
	if (isExternal(w))
		return-1;
	else
		return w->key;
}
void printAvlTree(node* w) {
	if (isInternal(w)) {
		printf(" %d", w->key);
		printAvlTree(w->left);
		printAvlTree(w->right);
	}
}
int main() {
	struct node* root=getnode();
	char cmd = -1;
	while (cmd != 'q') {
		scanf("%c", &cmd);
		int key;
		if (cmd == 'i') {
			scanf("%d", &key);
			getchar();
			root=insertItem(root, key);
		}
		else if (cmd == 's') {
			scanf("%d", &key);
			getchar();
			int i = findElement(root, key);
			if (i == -1) {
				printf("X\n");
			}
			else
				printf("%d\n",i);
		}
		else if (cmd == 'p') {
			getchar();
			printAvlTree(root);
			printf("\n");
		}
	}
}