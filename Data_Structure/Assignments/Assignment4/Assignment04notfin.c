#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int n = 0;
typedef struct node {
	struct node* next;
	int data;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	return p;
}
void emptyqueueexception() {
	printf("Empty Stack Exception!!");
}
void putnode(node *p) {
	free(p);
	return;
}
int is_empty(node* p) {
	return p == NULL;
}
void enqueue(node** f, node** r, int e) {
	n++;
	node* p = getnode();
	p->data = e;
	p->next = NULL;
	if (is_empty(*f)) {
		*f = p;
		*r = p;
	}
	else {
		(*r)->next = p;
		*r = p;
	}
}
int dequeue(node** f, node** r) {
	n--;
	if (is_empty(*f)) {
		emptyqueueexception();
	}
	int e = (*f)->data;
	node** p = f;
	*f = (*f)->next;
	if (*f == NULL)
		*r = NULL;
	putnode(*p);
	return e;
}
int front(node* f) {
	if (is_empty(f))
		emptyqueueexception();
	return f->data;
}
int is_emptystack(node* F1) {
	if (is_empty(F1)) {
		printf("Empty");
		return;
	}
	printf("Nonempty");
	return;
}
int top(node* F1, node* F2, node* R1, node* R2) {
	if (is_empty(F1)) {
		emptyqueueexception();
		return NULL;
	}
	while (is_empty(F1->next)!=1) {
		enqueue(&F2, &R2, dequeue(&F1, &R1));
	}
	int e = F1->data;
	enqueue(&F2, &R2, dequeue(&F1, &R1));
	while (is_empty(F2)!=1) {
		enqueue(&F1, &R1, dequeue(&F2, &R2));
	}
	return e;
}
void push(node* F1, node* R1, int e) {
	enqueue(&F1, &R1, e);
}
void pushmillion(node* F1, node* R1) {
	int e;
	for (int i = 0; i < 1000000; i++) {
		e = rand() % 90 + 10;
		push(F1, R1, e);
	}
}
int pop(node* F1, node* R1, node* F2, node* R2) {
	if (is_empty(F1)) {
		emptyqueueexception();
		return NULL;
	}
	while (is_empty(F1->next)!=1) {
		enqueue(&F2, &R2, dequeue(&F1, &R1));
	}
	int e = F1->data;
	dequeue(&F1, &R1);
	while (is_empty(F2)!=1) {
		enqueue(&F1, &R1, dequeue(&F2, &R2));
	}
	return e;
}
int main() {
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);
	double sec;

	struct node* F1 = getnode();
	struct node* F2 = getnode();
	struct node* R1 = getnode();
	struct node* R2 = getnode();

	F1 = NULL;
	F2 = NULL;
	R1 = NULL;
	R2 = NULL;

	char cmd='a';
	int e;
 	while (cmd != 'q') {
		scanf("%c", &cmd);
		if (cmd == 'S') {
			getchar();
			QueryPerformanceCounter(&start);
			is_emptystack(F1);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf(" (%d), cputime = %013.10f\n", n, sec * 1000);
		}
		else if (cmd == 't') {
			getchar();
			QueryPerformanceCounter(&start);
			e=top(F1, F2, R1, R2);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			if(e!=NULL)
				printf("%d (%d), cputime = %013.10f\n", e, n, sec*1000);
			else
				printf(" (%d), cputime = %013.10f\n", n, sec * 1000);

		}
		else if(cmd=='p'){
			QueryPerformanceCounter(&start);
			if (scanf("%d", &e)) {
				enqueue(&F1,&R1,e);
			}
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			getchar();
			printf("OK (%d), cputime = %013.10f\n", n, sec*1000);

		}
		else if (cmd == 'P') {
			getchar();
			QueryPerformanceCounter(&start);
			pushmillion(F1, R1);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("OK (%d), cputime = %013.10f\n", n, sec*1000);

		}
		else if (cmd == 'o') {
			getchar();
			QueryPerformanceCounter(&start);
			e = pop(F1, R1, F2, R2);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			if(e!=NULL)
				printf("%d (%d), cputime = %013.10f\n", e, n, sec*1000);
			else
				printf(" (%d), cputime = %013.10f\n", n, sec * 1000);
		}

	}


}
