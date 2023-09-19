#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int H, W, N;
		int a=100, b=1;
		scanf("%d %d %d", &H, &W, &N);
		int *A = (int*)malloc(sizeof(int)*H*W);
		for (int j = 0; j < H* W; j++) {
			A[j] = a + b;
			a += 100;
			if (a > H * 100) {
				b++;
				a = 100;
				if (a > H * 100 && b > W)
					break;
			}
		}
		printf("%d\n", A[N-1]);
	}
	return 0;
}