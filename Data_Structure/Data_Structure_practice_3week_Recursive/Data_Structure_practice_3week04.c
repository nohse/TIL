#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>
int recursive_max(int, int);
int main() {
	int N;
	scanf("%d", &N);

	printf("%d", recursive_max(N, INT_MIN));
}
int recursive_max(int N, int max) {
	int a;
	scanf("%d", &a);
	if (max < a)
		max = a;
	if (N == 1)
		return max;
	else
		recursive_max(N - 1, max);
}