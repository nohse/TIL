#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int sum(int);
int main() {
	int N;
	scanf("%d", &N);
	printf("%d", sum(N));

	return 0;
}
int sum(int N) {
	if (N == 1)
		return 1;
	else
		return sum(N - 1) + N;
}

