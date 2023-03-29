#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N, M;
	int i, j, num = 1, a;
	int arr[100][100];
	scanf("%d %d", &N, &M);
	for (j = 0; j < M; j++) {
		i = 0;
		a = j;
		while (a !=-1&&i<N) {
			arr[i][a] = num++;
			i++;
			a--;
		}

	}
	for (i = 1; i<N; i++) {
		j = M - 1;
		a = i;
		while (a != N&&j!=-1) {
			arr[a][j] = num++;
			a++;
			j--;
		}

	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}

		printf("\n");
	}

	return 0;
}