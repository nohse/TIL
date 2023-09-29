#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int N, M;
	int arr[1000001] = { 0};
	scanf("%d", &M);
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		for (int j = 2; i * j <= N; j++) {
			arr[i * j] = 1;
		}
	}
	for (int i = M; i <= N; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}