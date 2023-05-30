#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* left;
	struct node* right;
	int data;
	int id;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	return p;
}
node* setelement(int id, int data) {
	struct node* p = getnode();
	p->id = id;
	p->data = data;
	return p;
}
void putnode(node* p) {
	free(p);
}
int isinternal(node* p) {
	int cnt=0;
	if (p->left != NULL)
		cnt++;
	else if (p->right != NULL)
		cnt++;
	if (cnt == 0)
		return 0;
	else
		return 1;
}
node* insertnode(node* parent,node* left, node* right) {
	struct node* p = getnode();
	p->left = left;
	p->right = right;
	return p;
}
void printnode(node* p) {
	if (p != NULL) {
		printf(" %d", p->data);
	}
}
node* findnode(node * tree, int id) {
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
void binarypreorder(node* p) {
	if (p != NULL) {
		printnode(p);
		if (isinternal(p)) {
			binarypreorder(p->left);
			binarypreorder(p->right);
		}
	}
}
void binaryinorder(node* p) {
	if (p != NULL) {
		if (isinternal(p)) {
			binaryinorder(p->left);
		}
		printnode(p);
		if (isinternal(p)) {
			binaryinorder(p->right);
		}
	}
}
void binarypostorder(node* p) {
	if (p != NULL) {
		if (isinternal(p)) {
			binarypreorder(p->left);
			binarypreorder(p->right);
		}
		printnode(p);
	}
}
int main() {
	struct node* root = setelement(1,20);
	root->left = setelement(2, 30);
	root->right = setelement(3, 50);
	root->left->left = setelement(4, 70);
	root->left->right = setelement(5, 90);
	root->right->right = setelement(6, 120);
	root->right -> right->left = setelement(7, 130);
	root->right->right->right = setelement(8, 80);
	int cmd, id;

	scanf("%d %d", &cmd, &id);

	node* foundNode = findnode(root, id);
	if (foundNode == NULL) {
		printf("-1\n");
	}
	else {
		if (cmd == 1) {
			binarypreorder(foundNode);
		}
		else if (cmd == 2) {
			binaryinorder(foundNode);
		}
		else if (cmd == 3) {
			binarypostorder(foundNode);
		}
		else
			printf("-1\n");
	}
	return 0;
}