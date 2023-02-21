# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

	int a, b;
	a = 123;
	int *a_ptr = &a;
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	*a_ptr = 432;
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	//b = a_ptr;
	b = *a_ptr;
	printf("%d\n", b);

	*a_ptr = 789;
	printf("%d\n", b);
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	b = 12;
	printf("%d\n", b);
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	a = 1004;
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	return 0;
}