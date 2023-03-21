#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void recursive_cipher(int);
int main() {
	int N;
	scanf("%d", &N);
	recursive_cipher(N);
	return 0;
}
void recursive_cipher(int N) {
	if (N / 10 != 0) {
		printf("%d\n", N % 10);
		recursive_cipher(N / 10);
	}
	else
		printf("%d\n", N % 10);
}