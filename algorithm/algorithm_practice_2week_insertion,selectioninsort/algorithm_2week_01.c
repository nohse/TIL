#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int arr[], int n) {
	for (int pass = 1; pass <= n - 1; pass++) {
		int save = arr[pass];
		int j = pass - 1;
		while ((j >= 0) && (arr[j] > save)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = save;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr+i);
	}
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf(" %d", *(arr + i));
	}
	return 0;
}