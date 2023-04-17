#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	struct node* next;
	int data;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->next = NULL;

	return p;
}
void putnode(node* p) {
	free(p);
}
void appendterm(node* p, int data) {
	node*q = getnode();
	while (p->next != NULL) {
		p = p->next;
	}
	p->data = data;
	p->next = q;
}
int subset(node* a, node* b) {
	while (a->next != NULL && b ->next!= NULL) {
		if (a->data == b->data) {
			a = a->next;
			b = b->next;
		}
		else if (a->data > b->data) {
			b = b->next;
		}
		else if (a->data < b->data) {
			return a->data;
		}
	}
	if (a->next == NULL)
		return 0;
	else
		return a->data;
}
void print(node* a) {
	while (a->next != NULL) {
		printf(" %d", a->data);
		a = a->next;
	}
	printf("\n");
}
int main() {
	struct node* A = getnode();
	struct node* B = getnode();
	int N, data;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		appendterm(A, data);
	}
	//print(A);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		appendterm(B, data);
	}
	//print(B);
	printf("%d \n", subset(A, B));

	putnode(A);
	getnode(B);

	return 0;
}