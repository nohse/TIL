#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* left;
	struct node* right;
	int data;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	return p;
}
void putnode(node *p) {
	free(p);
}
void print(node* p) {
	printf("%d ", p->data);
	if (p->left != NULL) {
		printf("%d ", p->left->data);
	}
	if (p->right != NULL) {
		printf("%d\n", p->right->data);
	}
}
int main(){
	struct node* F1 = getnode();
	struct node* F2 = getnode();
	struct node* F3 = getnode();
	struct node* F4 = getnode();
	struct node* F5 = getnode();
	struct node* F6 = getnode();
	struct node* F7 = getnode();
	struct node* F8 = getnode();
	struct node* F9 = getnode();
	F1->data = 20;
	F2->data = 30;
	F3->data = 50;
	F4->data = 70;
	F5->data = 90;
	F6->data = 120;
	F7->data = 130;
	F8->data = 80;
	F1->left = F2;
	F1->right = F3;
	F2->left = F4;
	F2->right = F5;
	F3->right = F6;
	F6->left = F7;
	F6->right = F8;
	int n;
	scanf("%d", &n);
	if (n == 1) {
		print(F1);
	}
	else if (n == 2) {
		print(F2);
	}
	else if (n == 3) {
		print(F3);
	}
	else if (n == 4) {
		print(F4);
	}
	else if (n == 5) {
		print(F5);
	}
	else if (n == 6) {
		print(F6);
	}
	else if (n == 7) {
		print(F7);
	}
	else if (n == 8) {
		print(F8);
	}
	else {
		printf("-1\n");
	}

	return 0;
}