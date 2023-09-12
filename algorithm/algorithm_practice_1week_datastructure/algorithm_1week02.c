#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* left;
	struct node* right;
	int data;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));

	return p;
}
void putnode(node*p) {
	free(p);

	return;
}
int isInternal(node* p) {
	return ((p->left != NULL) || (p->right != NULL));
}
node* findnode(node * root,int m) {
	if (root == NULL)
		return NULL;

	if (root->data == m)
		return root;

	node* foundNode = findnode(root->left, m);
	if (foundNode != NULL)
		return foundNode;

	foundNode = findnode(root->right, m);
	if (foundNode != NULL)
		return foundNode;

	return NULL;
}
node* maketree(node* root,int m, int l, int r) {
	node* target = getnode();
	node* left = getnode();
	node* right = getnode();
	target = findnode(root, m);
	if (l == 0)
		left = NULL;
	else
		left->data = l;
	if (r == 0)
		right = NULL;
	else
		right->data = r;
	target->left = left;
	target->right = right;
	return root;
}
void printdata(node* root, char com[101]) {
	int i = 0;
	while (com[i] != NULL) {
		printf(" %d", root->data);
		if (com[i] == 'R') {
			root = root->right;
		}
		else if(com[i] == 'L') {
			root = root->left;
		}
		i++;
	}
	printf(" %d\n",root->data);
	return;
}
int main() {
	int n;
	int m, l, r;
	struct node* root = getnode();
	scanf("%d", &n);
	scanf("%d %d %d", &m, &l, &r);
	struct node* left = getnode();
	struct node* right = getnode();
	root->data = m;
	left->data = l;
	right->data = r;
	root->left = left;
	root->right = right;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &m, &l, &r);
		root = maketree(root, m, l, r);
	}
	int s;
	char com[101];
	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", com);
		printdata(root,com);
	}
	return 0;
}