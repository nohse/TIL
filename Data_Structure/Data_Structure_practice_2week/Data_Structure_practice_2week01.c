#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int modulo(int, int);
int main(void) {

	int a, b;
	int result;
	scanf("%d %d", &a, &b);
	result = modulo(a, b);
	printf("%d", result);

	return 0;
}
int modulo(int a, int b) {
	int i;
	while (a >= b) {
		a -= b;
	}

	return a;
}