#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int gcd(int, int);
int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d", gcd(A, B));

	return 0;
}
int gcd(int A, int B) {
	if (B == 0)
		return A;
	else
		gcd(B, A % B);
}