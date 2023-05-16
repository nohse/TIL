#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int front = 0, rear = 0;
void Print(int* queue, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", queue[i]);
	}
	printf("\n");
}
int Isempty(int n) {
	return (rear) % n == front;
}
int Isfull(int n) {
	return(rear + 1) % n == front;
}

int enqueue(int* queue, int n, int e) {
	if (Isfull(n)) {
		printf("overflow");
		Print(queue, n);
		return -1;
	}
	rear = (rear + 1) % n;
	queue[rear] = e;
}

int dequeue(int* queue, int n) {
	if (Isempty(n)) {
		printf("underflow");
		return -1;
	}
	front = (front + 1) % n;
	int e = queue[front];
	queue[front] = 0;
	return e;

}
int main() {
	int q, n, e;
	char cmd;
	scanf("%d", &q);
	int *queue=(int *)malloc(sizeof(int)*q);
	for (int i = 0; i < q; i++) {
		queue[i] = 0;
	}
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &cmd);
		if (cmd == 'I') {
			scanf("%d", &e);
			getchar();
			if(enqueue(queue, q, e)==-1)
				break;
		}
		else if (cmd == 'D') {
			getchar();
			if (dequeue(queue, n) == -1)
				break;
		}
		else if (cmd == 'P') {
			getchar();
			Print(queue, q);
		}
	}

}