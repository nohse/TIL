#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* left;
	struct node* right;
	struct node* parent;
	int key;
}node;
node* root = NULL;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	p->key = NULL;
	return p;
}
int isExternal(node* w) {
	return w->left == NULL && w->right == NULL;
}
int isInternal(node* w) {
	return w->left != NULL || w->right != NULL;
}
int isRoot(node* w) {
	return w == root;
}
void putnode(node* p) {
	free(p);
}
node* sibling(node* w) {
	if (isRoot(w))
		return;
	if (w->parent->left == w)
		return w->parent->right;
	else
		return w->parent->left;
}
node* inOrderSucc(node* w) {
	w = w->right;
	if (isExternal(w)) {
		return NULL;
	}
	while (isInternal(w->left)) {
		w = w->left;
	}

	return w;
}
node* reduceExternal(node* z) {
	node* w = z->parent;
	node* zs = sibling(z);
	if (isRoot(w)) {
		root = zs;
		zs->parent = NULL;
	}
	else {
		node* g = w->parent;
		zs->parent = g;
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	}
	putnode(z);
	putnode(w);
	return zs;
}
node* treeSearch(node* v, int k) {
	if(isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key) {
		return treeSearch(v->left, k);
	}
	else
		return treeSearch(v->right, k);
}
int findElement(int k) {
	node* w = treeSearch(root, k);
	if (isExternal(w))
		return-1;
	else
		return w->key;
}
void expandExternal(node* w) {
	node* a = getnode();
	node* b = getnode();
	w->right = a;
	w->left = b;
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
void insertItem(int k) {
	node* w = treeSearch(root, k);
	if (isInternal(w))
		return;
	else {
		w->key = k;
		expandExternal(w);
		return;
	}
}
void printPreOrder(node *v) {
	if (v->key==NULL)
		return;
	printf(" %d", v->key);
	if (isInternal(v->left)||isInternal(v->right)) {
		printPreOrder(v->left);
		printPreOrder(v->right);
	}
}
int removeElement(int k) {
	node* w = treeSearch(root, k);
	//node* parent;
	//node* cursor = root;
	//while (1) {
	//	if (cursor->left->key == w->key || cursor->right->key == w->key) {
	//		parent = cursor;
	//		break;
	//	}
	//	else if (cursor->key < w->key) {
	//		cursor = cursor->left;
	//	}
	//	else
	//		cursor = cursor->right;
	//}
	//w->parent = parent;
	if (isExternal(w))
		return -1;
	int e = w->key;
	node* z = w->left;
	z->parent = w;
	if (!isExternal(z)) {
		z = w->right;
		z->parent = w;
	}
	if (isExternal(z))
		reduceExternal(z);
	else {
		node* y = inOrderSucc(w);
		z = y->left;
		z->parent = y;
		w->key = y->key;
		reduceExternal(z);
	}
	if (e != -1)
		printf("%d\n", e);
	else printf("X\n");
	return e;
}
int main() {
	root = getnode();
	char cmd='a';
	while (cmd != 'q') {
		scanf("%c", &cmd);
		if (cmd == 'i') {
			int k;
			scanf("%d", &k);
			getchar();
			insertItem(k);
		}
		else if (cmd == 'd') {
			int k;
			scanf("%d", &k);
			getchar();
			if(removeElement(k)==-1)
				printf("X\n");
		}
		else if (cmd == 's') {
			int k;
			scanf("%d", &k);
			getchar();
			if (findElement(k) != -1) {
				printf("%d\n", findElement(k));
			}
			else
				printf("X\n");
		}
		else if (cmd == 'p') {
			printPreOrder(root);
			printf("\n");
		}
		else if (cmd == 'q')
			break;
	}

	free(root);
	return 0;
}