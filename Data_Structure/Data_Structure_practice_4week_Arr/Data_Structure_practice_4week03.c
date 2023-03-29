#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N;
	int arr[100][100];
	int i, j, cnt=1, flag=1;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		if (flag == 1) {
			for (j = 0; j < N; j++) {
				arr[i][j] = cnt;
				cnt++;
			}
			flag = 0;
		}
		else if (flag == 0) {
			for (j = N - 1; j >= 0; j--) {
				arr[i][j] = cnt;
				cnt++;
			}
			flag = 1;
		}
		
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
			
	}
	return 0;

}