#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	struct node* left;
	struct node* right;
	int id;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	return p;
}
node* setelement(int id) {
	struct node* p = getnode();
	p->id = id;
	return p;
}
void putnode(node* p) {
	free(p);
}
int isinternal(node* p) {
	int cnt = 0;
	if (p->left != NULL)
		cnt++;
	else if (p->right != NULL)
		cnt++;
	if (cnt == 0)
		return 0;
	else
		return 1;
}
void insertnode(node* parent, int y, int z) {
	struct node* p = getnode();
	struct node* q = getnode();
	if (y == 0)
		p = NULL;
	else {
		parent->left = p;
		p->id = y;
	}
	if (z == 0)
		q = NULL;
	else {
		parent->right = q;
		q->id = z;
	}
}
void printnode(node* p, char cmd[101]) {
		for (int i = 0; i < strlen(cmd); i++) {
			if (p != NULL) {
				printf(" %d", p->id);
			}
			if (cmd[i] == 'L')
				p = p->left;
			else
				p = p->right;
		}
		printf(" %d\n", p->id);
}
node* findnode(node* tree, int id) {
	if (tree == NULL)
		return NULL;

	if (tree->id == id)
		return tree;

	node* foundNode = findnode(tree->left, id);
	if (foundNode != NULL)
		return foundNode;

	foundNode = findnode(tree->right, id);
	if (foundNode != NULL)
		return foundNode;

	return NULL;
}
//void binarypreorder(node* p) {
//	if (p != NULL) {
//		printnode(p);
//		if (isinternal(p)) {
//			binarypreorder(p->left);
//			binarypreorder(p->right);
//		}
//	}
//}
//void binaryinorder(node* p) {
//	if (p != NULL) {
//		if (isinternal(p)) {
//			binaryinorder(p->left);
//		}
//		printnode(p);
//		if (isinternal(p)) {
//			binaryinorder(p->right);
//		}
//	}
//}
//void binarypostorder(node* p) {
//	if (p != NULL) {
//		if (isinternal(p)) {
//			binarypreorder(p->left);
//			binarypreorder(p->right);
//		}
//		printnode(p);
//	}
//}
int main() {
	struct node* root;
	int nodenum;
	int  id;
	int x, y, z;
	scanf("%d", &nodenum);
	scanf("%d %d %d", &x, &y, &z);
	root = setelement(x);
	insertnode(root, y, z);

	for (int i = 0; i < nodenum-1; i++) {
		scanf("%d %d %d", &x, &y, &z);
		insertnode(findnode(root, x), y, z);
	}
	scanf("%d", &nodenum);
	char cmd[101];
	for (int i = 0; i < nodenum; i++) {
		scanf("%s", cmd);
		getchar();
		printnode(root, cmd);
	}
	return 0;
}