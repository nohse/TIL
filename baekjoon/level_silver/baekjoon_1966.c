#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int num = 1;
typedef struct node {
	struct node* next;
	int imp;
	int flag;
}node;
typedef struct Queue {
	node* front;
	node* rear;
	int max;
	int cnt;
}queue;
void initQueue(queue* q) {
	q->front = NULL;
	q->rear = NULL;
	q->cnt = 0;
	q->max = 0;
}
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
void putnode(node * p) {
	free(p);
}
int isEmpty(queue *q){
	return (q->cnt == 0);
}
void enqueue(queue* q, int imp, int flag) {
	struct node *p = getnode();
	p->imp = imp;
	p->flag = flag;

	if ((p->imp) > q->max) {
		q->max = imp;
	}
	if (isEmpty(q)) {
		q->rear = p;
		q->front = p;
	}
	else {
		q->rear->next = p;
		q->rear = p;
	}
	q->cnt++;
	return;
}
void checkimp(queue* q) {
	node* p = q->front;
	int max = -1;
	while (p != NULL) {
		if ((p->imp) > max) {
			max = p->imp;
		}
		p = p->next;
	}
	q->max = max;
}
int dequeue(queue* q) {

	node* p = q->front;
	int imp = p->imp;
	int flag = p->flag;
	q->front = q->front->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	putnode(p);
	q->cnt--;
	if (imp < q->max) {
		enqueue(q, imp, flag);
	}
	else {
		if (flag == 1) {
			return -1;
		}
		num++;
	}
	checkimp(q);
	return imp;
}
int main() {
	queue q;
	int N;
	int testsize, finindex = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		initQueue(&q);
		scanf("%d %d", &testsize, &finindex);
		num = 1;
		for (int j = 0; j < testsize; j++) {
			int imp;
			scanf("%d", &imp);
			if (j == finindex)
				enqueue(&q, imp, 1);
			else
				enqueue(&q, imp, 0);
		}
		while (1) {
			int a=dequeue(&q);
			if (a == -1) {
				printf("%d\n", num);
				break;
			}
		}

	}
}
