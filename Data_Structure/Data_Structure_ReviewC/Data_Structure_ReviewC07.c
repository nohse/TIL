#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int* arr1;
	int* arr2;
	int N;
	int i;
	scanf("%d", &N);
	arr1 = (int*)malloc(sizeof(int) * N);
	arr2 = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &arr2[i]);
	}

	for (i = 0; i < N; i++) {
			printf(" %d", arr1[i] + arr2[N - i-1]);
	}

	return 0;

}