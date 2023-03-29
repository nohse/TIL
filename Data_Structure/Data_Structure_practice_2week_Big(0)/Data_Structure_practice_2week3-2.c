#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int* prefixAverages1(int*, int);
int* prefixAverages2(int*, int);
int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);
	int N;
	int* X, * A;
	scanf("%d", &N);
	X = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	QueryPerformanceCounter(&start);
	A = prefixAverages1(X, N);
	// 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart-start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");


	QueryPerformanceCounter(&start);
	A = prefixAverages2(X, N);
	// 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}

int* prefixAverages1(int* X, int N) {
	int i, j;
	double sum;
	int* A;
	A = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum = sum + X[j];
		}
		A[i] = (sum / (i + 1)) + 0.5;
	}
	return A;
}
int* prefixAverages2(int* X, int N) {
	int i;
	int* A;
	double sum = 0;
	A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		sum += X[i];
		A[i] = (sum / (i + 1) + 0.5);
	}
	return A;

}
