#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int findmatrix(int A[][8]) {
	int sum=0;
	int i = 0;
	for (int j = 7; j >= 0; j--) {
		if (A[i][j] == 1) {
			sum = sum + 1 + j;
			i++;
			j++;
		}
	}

	return sum;
}

int main() {
	int A[8][8];
	int i, j, result;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	result = findmatrix(A);
	printf("%d", result);

	return 0;
}