#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	struct node* pre;
	int data;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->pre = NULL;
	return p;
}
void putnode(node* p) {
	free(p);
}
void appendterm(node* head, int e) {
	struct node* p = getnode();
	while (head->next != NULL) {
		head = head->next;
	}
	p->next = head;
	p->pre = head->pre;
	p->data = e;
	head->pre->next = p;
	head->pre = p;

}
int subset(node* a, node* b) {
	int flag = 0;
	while (a->next != NULL && b->next != NULL) {
		if (a->data > b->data) {
			b = b->next;
		}
		else if (a->data < b->data) {
			return a->data;
		}
		else if (a -> data == b->data) {
			a = a->next;
			b = b->next;
		}
	}
	if (a->next != NULL)
		return a->data;
	else
		return 0;
}

int main() {
	node* Ahead = getnode();
	node* Atail = getnode();
	node* Bhead = getnode();
	node* Btail = getnode();

	Ahead->next = Atail;
	Atail->pre = Ahead;

	Bhead->next = Btail;
	Btail->pre = Bhead;

	int N, e;

	scanf("%d", &N);
	if (N != 0) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &e);
			appendterm(Ahead, e);
		}
	}

	scanf("%d", &N);
	if (N != 0) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &e);
			appendterm(Bhead, e);
		}
	}
	printf("%d", subset(Ahead, Bhead));

	putnode(Ahead);
	putnode(Atail);
	putnode(Bhead);
	putnode(Btail);
	return 0;

}