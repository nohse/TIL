#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void selection_sort(int arr[], int n) {
	for (int pass = 0; pass <= n - 2; pass++) {
		int minLoc = pass;
		for (int j = pass + 1; j<= n - 1;j++) {
			if (arr[j] < arr[minLoc])
				minLoc = j;
		}
		int tmp = arr[pass];
		arr[pass] = arr[minLoc];
		arr[minLoc] = tmp;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	selection_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf(" %d", *(arr + i));
	}
	return 0;
}