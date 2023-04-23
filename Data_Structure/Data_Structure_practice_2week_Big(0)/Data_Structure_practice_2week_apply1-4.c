#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int findmissingint(int A[], int a) {
	int i, sum=0;
	for (i = 0; i <= a; i++) {
		if (A[i] <= a) {
			sum += A[i];
		}
	}
	sum = a * (a + 1) / 2 - sum;
	return sum;

}
int main() {
	int n, A[1000], result;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	result = findmissingint(A, n);
	printf("%d", result);

	return 0;
}