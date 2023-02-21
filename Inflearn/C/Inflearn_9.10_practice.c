#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibonacci(int n);
int main() {
	for (int count = 1; count < 13; count++) {
		printf("%d ", fibonacci(count));
	}

	return 0;
}

int fibonacci(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}