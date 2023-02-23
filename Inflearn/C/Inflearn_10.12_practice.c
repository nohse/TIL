#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 3;
	int* ptr = &a;
	*ptr = 8;
	int** pptr = &ptr;
	if (pptr == &ptr)
		printf("Same\n");
	if (*pptr == &a)
		printf("Same\n");
	if (**pptr == a)
		printf("Same\n");

	return 0;
}