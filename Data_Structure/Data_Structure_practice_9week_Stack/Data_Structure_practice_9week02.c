#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int t=-1;
int cnt=0;
void fullStackException() {
	printf("Stack FULL\n");
}
void emptyStackException() {
	printf("Stack Empty\n");
}
int isEmpty() {
	if (t == -1)
		return 1;
	else
		return 0;
}
void push(char stack[], char a) {
	if (t == 99999) {
		fullStackException();
	}
	t = t + 1;
	stack[t] = a;
}
char pop(char stack[]) {
	if (isEmpty == 1) {
		emptyStackException();
		return 0;
	}
	t = t - 1;
	return stack[t + 1];
}
void makingsymbolstack(char arr[], char stack[]) {
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '(' || arr[i] == ')' || arr[i] == '{' || arr[i] == '}' || arr[i] == '[' || arr[i] == ']') {
			push(stack, arr[i]);
		}
	}
	return;
}
int isOpensymbol(char a) {
	if (a == '{' || a == '(' || a == '[') {
		return 1;
	}
	else return 0;
}
int isClosesymbol(char a) {
	if (a == '}' || a == ')' || a == ']') {
		return 1;
	}
	else return 0;
}
int Counterpart(char a, char s) {
	if (s == '{' && a == '}')
		return 0;
	else if (s == '(' && a == ')')
		return 0;
	else if (s == '[' && a == ']')
		return 0;
	return 1;

}
int isBalanced(char *stack) {
	char S[100000];
	char s;
	int cnto = 0, cntc = 0;
	char compare;
	int i = 0;
	int flag = 1;
	while (stack[i] != NULL) {
		s = stack[i];
		if (isOpensymbol(s) == 1) {
			cnt++;
			push(S,s);
			cnto++;
		}
		else if (isClosesymbol(s) == 1) {
			cnt++;
			cntc++;
			if (isEmpty(S) == 1) {
				flag= 0;
			}
			compare = pop(S);
			if (Counterpart(s, compare)==1) {
				flag= 0;
			}

		}
		i++;
	}
	if (flag == 0)
		return 0;
	else if (cnto == cntc&&flag==1)
		return 1;
	else
		return 0;
}
int main() {
	char arr[100000];
	scanf("%[^\n]s", arr);
	getchar();
	char stack[100000]={NULL};
	makingsymbolstack(arr,stack);
	if (isBalanced(stack)) {
		printf("OK_%d\n", cnt);
	}
	else{
		printf("Wrong_%d\n", cnt);
	}
}