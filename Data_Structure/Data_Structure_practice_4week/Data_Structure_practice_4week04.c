#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int arr[100][1000] = { 0 };
	int N, M;
	scanf("%d %d", &N, &M);
	int i=0, j=0, num = 2;
	arr[0][0] = 1;

	while (num <= N * M) {

		while (j + 1 < M && arr[i][j + 1] == 0) {
			j++;
			arr[i][j] = num++;
		}
		while (i + 1 < N && arr[i + 1][j] == 0) {
			i++;
			arr[i][j] = num++;
		}
		while (j - 1 >= 0 && arr[i][j - 1] == 0) {
			j--; arr[i][j] = num++;
		}
		while (i - 1 >= 0 && arr[i - 1][j] == 0) {
			i--;
			arr[i][j] = num++;
		}
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}