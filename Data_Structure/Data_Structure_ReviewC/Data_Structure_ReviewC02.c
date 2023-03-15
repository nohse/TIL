#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void ABC(int[], int);

int main() {
	int arr[10];
	int k;
	for (k = 0; k < 10; k++) {
		scanf("%d", &arr[k]);
	}
	for (k = 0; k < 9; k++) {
		ABC(arr, k);
	}

	for (k = 0; k < 10; k++) {
	printf(" %d", arr[k]);
	}

	return 0;
}

void ABC(int arr[], int n) {
	int tmp, max_index = n;
	int i;
	for (i = n + 1; i < 10; i++) {
		if (arr[max_index] < arr[i])
			max_index = i;
	}
	tmp = arr[max_index];
	arr[max_index] = arr[n];
	arr[n] = tmp;
}