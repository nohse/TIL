#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
void insertionsort(int A[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int save = A[i];
		j = i - 1;
		while (j >= 0 && save < A[j]) {
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = save;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int* A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	insertionsort(A, n);
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
}