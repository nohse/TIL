#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int i, int j) {
	int tmp;
	tmp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = tmp;

	return;
}
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (*(arr + j) < *(arr + j-1))
				swap(arr, j-1, j);
		}
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", *(arr + i));
	}
	return 0;
}