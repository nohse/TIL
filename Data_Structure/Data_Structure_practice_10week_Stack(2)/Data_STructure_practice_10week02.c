#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int t = -1;
void push(int s[], int e) {
	t++;
	s[t] = e;
}
int pop(int s[]) {
	t--;
	return s[t + 1];
}
int IsOperand(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}
int doOperator(char c, int a, int b) {
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '/')
		return a / b;
	else if (c == '*')
		return a * b;
}
void evaluate(char arr[]) {
	int s[101];
	int a, b;
	for (int i = 0; i < strlen(arr); i++) {
		if (IsOperand(arr[i]) == 1)
			push(s, arr[i]-'0');
		else {
			a = pop(s);
			b = pop(s);
			push(s, doOperator(arr[i], b, a));
		}
	}
	printf("%d\n", pop(s));
	return 0;
}
int main() {
	char arr[101];
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", arr);
		getchar();
		evaluate(arr);
	}
}
