#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//int a;
	//a = 1234;
	//printf("%p\n", &a);
	//printf("%d\n", a);

	//int* ptr=1234;
	//printf("%p\n", ptr);
	//printf("%d\n", *ptr);
	int* safer_ptr=NULL;
	int a = 123;
	int b;
	scanf("%d", &b);
	if (b % 2 == 0)
		safer_ptr = &a;
	
	if (safer_ptr != NULL)
		printf("%p\n", safer_ptr);
	if (safer_ptr != NULL)
		printf("%d\n", *safer_ptr);

	return 0;
}
//포인터에 아무 주소도 대입 되지 않아 런타임 에러가 일어나는 상황을 막기 위해 NULL 포인터를 사용해줌
