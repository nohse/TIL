#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int* prefixAverages1(int*, int);
int* prefixAverages2(int*, int);
int main() {
	int N;
	int* X, *A;
	scanf("%d", &N);
	X = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	A = prefixAverages1(X, N);
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	A = prefixAverages2(X, N);
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}

	return 0;
}
int* prefixAverages1(int* X, int N) {
	int i, j;
	double sum;
	int* A;
	A = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N ; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum = sum + X[j];
		}
		A[i] = (sum / (i + 1))+0.5;
	}
	return A;
}
int* prefixAverages2(int* X, int N) {
	int i;
	int* A;
	double sum = 0;
	A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		sum += X[i];
		A[i] = (sum / (i + 1) + 0.5);
	}
	return A;

}