#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int sizea = 0, sizeb = 0, sizeresult;
typedef struct node {
	struct node* next;
	struct node* pre;
	int ex;
	int coef;

}node;
void appendterm(node* p, int c, int e)
{
	node* q = (node*)malloc(sizeof(node));
	while (p->next != NULL) {
		p = p->next;
	}
	q->ex = e;
	q->coef = c;
	q->next = p;
	q->pre = p->pre;
	p->pre->next = q;
	p->pre = q;
}
node* add(node* a, node* b) {
	node* rhead = (node*)malloc(sizeof(node));
	node* rtail = (node*)malloc(sizeof(node));

	rhead->next = rtail;
	rhead->pre = NULL;
	rtail->pre = rhead;
	rtail->next = NULL;

	a = a->next;
	b = b->next;
	while (a ->next!= NULL && b->next != NULL) {
		if (a->ex > b->ex) {
			appendterm(rhead, a->coef, a->ex);
			a = a->next;
		}
		else if (a->ex < b->ex) {
			appendterm(rhead, b->coef, b->ex);
			b = b->next;
		}
		else
		{
			if (a->coef + b->coef != 0) {
				appendterm(rhead, a->coef + b->coef, a->ex);
			}
			a = a->next;
			b = b->next;
		}
	}
	while (a ->next!= NULL) {
		if (a->coef != 0) {
			appendterm(rhead, a->coef, a->ex);
			
		}
		a = a->next;
	}
	while (b ->next!= NULL) {
		if (b->coef != 0) {
			appendterm(rhead, b->coef, b->ex);
		}
		b = b->next;
	}
	return rhead;
}
void print(node* a) {
	a = a->next;
	while (a->next!= NULL) {
		printf(" %d %d", a->coef, a->ex);
		a = a->next;
	}
}
int main() {
	int e, c;
	int n;

	node* ahead = (node*)malloc(sizeof(node));
	node* atail = (node*)malloc(sizeof(node));
	node* bhead = (node*)malloc(sizeof(node));
	node* btail = (node*)malloc(sizeof(node));
	node* rhead = (node*)malloc(sizeof(node));

	ahead->next = atail;
	ahead->pre = NULL;
	atail->pre = ahead;
	atail->next = NULL;

	bhead->next = btail;
	bhead->pre = NULL;
	btail->pre = bhead;
	btail->next = NULL;

	

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		appendterm(ahead, c, e);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		appendterm(bhead, c, e);
	}
	rhead=add(ahead, bhead);
	print(rhead);

	return 0;
	
}