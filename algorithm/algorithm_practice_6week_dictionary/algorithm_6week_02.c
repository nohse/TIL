#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int findElement(int* arr, int k, int n) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] == k)
			return mid;
		else if (arr[mid] < k) {
			if (arr[mid - 1] > k)
				return mid - 1;
			l = mid + 1;
			continue;
		}
		else if (arr[mid] > k) {
			if (arr[mid + 1] < k)
				return mid;
			r = mid - 1;
			continue;
		}
	}
	return l;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr;
	int result;
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	result = findElement(arr, k, n);

	printf("%d", result);

	return 0;
}
