#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
void insertionsort(int A[], int n) {
	int i, j;
	for (int i = 0; i < n - 1; i++) {
		int minLoc = i;
		for (j = i + 1; j < n; j++) {
			if (A[minLoc] > A[j]) {
				minLoc = j;
			}
		}
		int tmp = A[minLoc];
		A[minLoc] = A[i];
		A[i] = tmp;
	}
}int main() {
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