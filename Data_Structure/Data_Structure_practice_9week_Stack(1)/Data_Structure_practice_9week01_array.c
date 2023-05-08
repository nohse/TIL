#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int t = -1;
int isEmpty(int t) {
	if (t == -1)
		return 0;
	else
		return -1;
}
void emptyStackException() {
	printf("Stack Empty\n");
}
void fullStackException() {
	printf("Stack FULL\n");
}
void push(char stack[], int N, char e) {
	if (t==N-1) {
		fullStackException();
		return ;
	}
	t = t + 1;
	stack[t] = e;
}
char pop(char stack[]) {
	if (isEmpty(t)==0) {
		emptyStackException();
		return 0;
	}
	t = t - 1;
	return stack[t+1];
}
void peek(char stack[]) {
	if (isEmpty(t)==0) {
		emptyStackException();
		return;
	}
	printf("%c\n", stack[t]);
}
 void duplicate(char stack[], int N) {
	if (t == N - 1) {
		fullStackException();
		return;
	}
	char e = pop(stack);
	push(stack, N, e);
	push(stack, N, e);
}
void upRotate(char stack[], int n) {
	if (t+1 < n||n<=0) return;
	char tmp;
	tmp = stack[t];
	for (int i = t-1; i > t-n; i--) {
		stack[i + 1] = stack[i];
	}
	stack[t-n+1] = tmp;
}
void downRotate(char stack[], int n) {
	if (t + 1 < n || n < 0) return;
	char tmp;
	tmp = stack[t-n+1];
	for (int i = t-n+1; i <t; i++) {
		stack[i] = stack[i+1];
	}
	stack[t] = tmp;
}
void print(char stack[]) {
	for (int i = t; i >= 0; i--) {
		printf("%c", stack[i]);
	}
	printf("\n");
}

int main() {
	int N;
	int num;
	char e;
	char command[8];
	int up;
	scanf("%d", &N);
	char* stack = (char*)malloc(sizeof(char) * N);
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", command);
		if (strcmp(command, "PUSH")== 0) {
			getchar();
			scanf("%c", &e);
			getchar();
			push(stack, N, e);
		}
		else if (strcmp(command, "POP") == 0) {
			getchar();
			pop(stack);
		}
		else if (strcmp(command, "PEEK") == 0) {
			getchar();
			peek(stack);
		}
		else if (strcmp(command, "DUP") == 0){
			getchar();
			duplicate(stack, N);
		}
		else if (strcmp(command, "UpR") == 0) {
			getchar();
			scanf("%d", &up);
			getchar();
			upRotate(stack, up);
		}
		else if (strcmp(command, "DownR") == 0) {
			getchar();
			scanf("%d", &up);
			getchar();
			downRotate(stack, up);
		}
		else if (strcmp(command, "PRINT") == 0) {
			getchar();
			print(stack);
		}
	}
	return 0;
}