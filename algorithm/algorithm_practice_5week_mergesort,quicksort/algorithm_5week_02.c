#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int findPivot(int A[], int l, int r) {
	return l + rand() % (r - l + 1);
}
int inPlacePartition(int A[], int l, int r, int k) {
	int p = A[k];
	int tmp = A[k];
	A[k] = A[r];
	A[r] = tmp;
	int i, j;
	i = l;
	j = r - 1;
	while (i <= j) {
		while (i <= j && A[i] < p)
			i++;
		while (j >= i && A[j] >= p)
			j--;
		if (i < j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i];
	A[i] = A[r];
	A[r] = tmp;
	j = r;
	i++;
	while (j != i) {
		if (A[i] != p) {
			while (A[j] != p && j != i) {
				j--;
			}
			if (A[j] == p) {
				tmp = A[j];
				A[j] = A[i];
				A[i] = tmp;
			}
		}
	}
	return i;

}
void inPlaceQuickSort(int A[], int l, int r) {
	if (l >= r)
		return;
	int k;
	int i;
	k = findPivot(A, l, r);
	i = inPlacePartition(A, l, r, k);
	inPlaceQuickSort(A, l, i - 1);
	inPlaceQuickSort(A, i + 1, r);
}
int main() {
	srand(time(NULL));
	int N;
	scanf("%d", &N);
	int* A = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	inPlaceQuickSort(A, 0, N - 1);
	for (int i = 0; i < N; i++) {
		printf(" %d", A[i]);
	}
	return 0;
}