#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int findElement(int* arr, int k, int n) {
	if (arr[n - 1] < k)
		return n - 1;
	if (arr[0] > k)
		return -1;
	return rFE(arr, 0, n-1, k);
}
int rFE(int* arr, int l, int r, int k) {
	if (l > r)
		return -1;
	int mid = (l + r) / 2;
	if (arr[mid] == k)
		return mid;
	else if (arr[mid] > k) {
		if (arr[mid - 1] < k)
			return mid - 1;
		rFE(arr, l, mid - 1, k);
	}
	else if(arr[mid]<k) {
		if (arr[mid + 1] > k)
			return mid;
		rFE(arr, mid + 1, r, k);
	}
}
int main() {
	int* arr;
	int n, k;
	scanf("%d %d", &n, &k);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int result = findElement(arr, k, n);
	printf("%d", result);
	return 0;
}