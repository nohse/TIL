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
void print(node* p) {
	if (p->next->next == NULL)
		printf("0\n");
	else {
		while (p->next->next != NULL) {
			p = p->next;
			printf("%d ", p->data);
		}
		printf("\n");
	}
}
node* unioon(node* a, node* b) {
	node* resulth = getnode();
	node* resultt = getnode();

	resulth->next = resultt;
	resultt->pre = resulth;
	a = a->next;
	b = b->next;
	while (a->next != NULL && b->next != NULL) {
		if (a->data > b->data){
			appendterm(resulth, b->data);
			b = b->next;
		}
		else if (a->data < b->data) {
			appendterm(resulth, a->data);
			a = a->next;
		}
		else if (a->data == b->data) {
			appendterm(resulth, a->data);
			a = a->next;
			b = b->next;
		}
	}
	while (a->next != NULL) {
		appendterm(resulth, a->data);
		a = a->next;
	}
	while (b->next != NULL) {
		appendterm(resulth, b->data);
		b= b->next;
	}

	return resulth;
}
node* intersect(node* a, node* b) {
	node* resulth = getnode();
	node* resultt = getnode();
	resulth->next = resultt;
	resultt->pre = resulth;

	a = a->next;
	b = b->next;

	while (a->next != NULL && b->next != NULL) {
		if (a->data < b->data) {
			a = a->next;
		}
		else if (a->data > b->data) {
			b = b->next;
		}
		else {
			appendterm(resulth, a->data);
			a = a->next;
			b = b->next;
		}
	}
	return resulth;
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

	node* unionresulthead = getnode();
	//node* unionresulttail = getnode();
	node* intersectresulthead = getnode();
	//node* intersectresulttail = getnode();

	//unionresulthead->next = unionresulttail;
	//unionresulttail->pre = unionresulthead;

	//intersectresulthead->next = intersectresulttail;
	//intersectresulttail->pre = intersectresulthead;

	unionresulthead = unioon(Ahead, Bhead);
	intersectresulthead = intersect(Ahead, Bhead);
	print(unionresulthead);
	print(intersectresulthead);

	putnode(Ahead);
	putnode(Atail);
	putnode(Bhead);
	putnode(Btail);
	putnode(unionresulthead);
	putnode(intersectresulthead);
	return 0;

}