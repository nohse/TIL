#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int A, B, C;
	int tmp;
	scanf("%d %d %d", &A, &B, &C);
	while (A != 0 || B != 0 || C != 0) {
		if (A > B) {
			tmp = A;
			A = B;
			B = tmp;
		}
		if (A > C) {
			tmp = A;
			A = C;
			C = tmp;
		}
		if (B > C) {
			tmp = C;
			C = B;
			B = tmp;
		}
		if ((A * A + B * B) == (C * C))
			printf("right\n");
		else
			printf("wrong\n");
		scanf("%d %d %d", &A, &B, &C);
	}

	return 0;
}