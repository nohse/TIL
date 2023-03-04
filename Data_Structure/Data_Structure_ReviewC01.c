#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int sum(int);
int main() {
	int n;

	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}
int sum(int n) {
	int i, j, sum=0;

	for (i = 1; i <= n; i++) {
		sum = sum + i * (n - i + 1);
	}

	return sum;
}