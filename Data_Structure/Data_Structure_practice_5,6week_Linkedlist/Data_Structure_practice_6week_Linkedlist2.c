#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int element;
	int coex;
	struct node* next;
}node;
void appendterm(node* p, int c, int e) {
	node* q = (node*)malloc(sizeof(node));
	q->coex = c;
	q->element = e;
	q->next = NULL;
	while (p->next!= NULL)
		p = p->next;
	p->next = q;
}
node* add(node* p, node* q) {
	node* result = (node*)malloc(sizeof(node));
	result->next = NULL;
	p = p->next;
	q = q->next;
	while (p!= NULL && q!= NULL) {
		if (p->element > q->element) {
			appendterm(result, p->coex, p->element);
			p = p->next;
		}
		else if (p->element < q->element) {
			appendterm(result, q->coex, q->element);
			q = q->next;
		}
		else if (p->element == q->element) {
			if (p->coex + q->coex != 0) {
				appendterm(result, p->coex + q->coex, p->element);
			}
			p = p->next;
			q = q->next;
		}
	}
	while (p!= NULL) {
		appendterm(result, p->coex, p->element);
		p = p->next;
	}
	while (q!= NULL) {
		appendterm(result, q->coex, q->element);
		q = q->next;
	}
	return result;
}
void print(node* p) {
	p = p->next;
	while (p!= NULL){
		printf(" %d %d", p->coex, p->element);
		p = p->next;
	}
}
int main() {
	struct node* ahead[3];
	ahead[0] = (node*)malloc(sizeof(node));
	ahead[1] = (node*)malloc(sizeof(node));
	ahead[0]->next = NULL;
	ahead[1]->next = NULL;
	int n, c, e;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &c, &e);
		appendterm(ahead[0], c, e);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &c, &e);
		appendterm(ahead[1], c, e);
	}
	ahead[2] = add(ahead[0], ahead[1]);
	print(ahead[2]);

	return 0;
}