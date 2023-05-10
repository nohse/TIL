#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
typedef struct node {
	struct node* next;
	int data;
	int min;
}node;
typedef struct stack{
	struct node* top;
	int t;
}stack;
void init(stack* s) {
	s->top = NULL;
	s->t = 0;
}
int is_empty(stack* s) {
	return(s->top == NULL);
}
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->min = MININT;
	return p;
}
void putnode(node* p) {
	free(p);
}
void push(stack* s, int e) {

	node* p = getnode();
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->t = s->t + 1;
	if (is_empty(p))
		p->min = e;
	else if (p->data < p->next->min) {
		p->min = p->data;
	}
	else
		p->min = p->next->min;
}
int pop(stack* s) {
	if (is_empty(s)) {
		printf("stack empty\n");
		return NULL;
	}
	else {
		node* p = s->top;
		int data = p->data;
		s->top = s->top->next;
		putnode(p);
		s->t = s->t -1;
		return data;
	}
}
void pushMillion(stack* s) {
	int e;
	for (int i = 0; i < 1000000; i++) {
		e = rand() % 9000 + 1000;
		push(s, e);
	}
	return;
}
void popMillion(stack* s) {
	for (int i = 0; i < 1000000; i++) {
		pop(s);
	}
	return;
}
int findMin(stack* s) {
	if (is_empty(s)) {
		printf("empty stack\n");
		return NULL;
	}
	return s->top->min;
}
int main() {
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);
	double sec;

	char cmd='a';
	int e;
	int result;

	struct stack s;
	init(&s);
	while (cmd != 'q') {
		scanf("%c", &cmd);
		if (cmd == 'p') {
			getchar();
			scanf("%d", &e);
			getchar();
			QueryPerformanceCounter(&start);
			push(&s, e);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("push %d (%d), cputime = %013.10f\n", e, s.t, sec*1000);
		}
		else if (cmd == 'P') {
			getchar();
			QueryPerformanceCounter(&start);
			pushMillion(&s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("pushMillion (%d), cputime = %013.10f\n", s.t, sec*1000);
		}
		else if (cmd == 'o') {
			getchar();
			QueryPerformanceCounter(&start);
			result = pop(&s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("pop %d (%d), cputime = %013.10f\n", result, s.t, sec*1000);
		}
		else if (cmd == 'O') {
			getchar();
			QueryPerformanceCounter(&start);
			popMillion(&s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("popMillion (%d), cputime = %013.10f\n", s.t, sec*1000);
		}
		else if (cmd == 'f') {
			getchar();
			QueryPerformanceCounter(&start);
			result = findMin(&s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("min %d (%d), cputime = %013.10f\n", result, s.t, sec*1000);
		}
	}
	printf("(프로그램 종료)\n");
	
	return 0;
}