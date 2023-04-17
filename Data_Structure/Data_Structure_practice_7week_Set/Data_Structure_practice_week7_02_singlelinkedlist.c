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
	node* q = getnode();
	while (p->next != NULL) {
		p = p->next;
	}
	p->data = data;
	p->next = q;
}

void print(node* a) {
	if (a->next == NULL) {
		printf("0\n");
	}
	else {

		while (a->next != NULL) {
			printf(" %d", a->data);
			a = a->next;
		}
		printf("\n");
	}
}
node* unioon(node* a, node* b) {
	struct node* result = getnode();
	while (a->next != NULL && b->next != NULL) {
		if (a->data > b->data) {
			appendterm(result, b->data);
			b = b->next;
		}
		else if (a->data < b->data) {
			appendterm(result, a->data);
			a = a->next;
		}
		else {
			appendterm(result, a->data);
			a = a->next;
			b = b->next;
		}
	}
	while (a->next != NULL) {
		appendterm(result, a->data);
		a = a->next;
	}
	while (b->next != NULL){
		appendterm(result, b->data);
		b = b->next;
		}
	return result;
}
node* intersect(node* a, node* b) {
	struct node* result = getnode();
	while (a->next != NULL && b->next != NULL) {
		if (a->data > b->data) {
			b = b->next;
		}
		else if (a->data < b->data) {
			a = a->next;
		}
		else {
			appendterm(result, a->data);
			a = a->next;
			b = b->next;
		}
	}

	return result;
}

int main() {
	struct node* A = getnode();
	struct node* B = getnode();
	struct node* unionresult = getnode();
	struct node* intersectresult = getnode();
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
	unionresult=unioon(A, B);
	intersectresult = intersect(A, B);
	print(unionresult);
	print(intersectresult);

	putnode(A);
	getnode(B);

	return 0;
}