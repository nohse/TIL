#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	int A, B, C;
	int result;
	int a[10] = {0};
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	result = A * B * C;
	while (result != 0) {
		a[result % 10]++;
		result = result / 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}