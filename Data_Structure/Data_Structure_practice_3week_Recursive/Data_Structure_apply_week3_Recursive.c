#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int recursive_multiple(int, int);
//int recursive_remain(int, int);
//int recursive_share(int, int);
//int main() {
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("a multiple b is %d\n", recursive_multiple(a, b));
//	printf("a divide b remain is %d\n", recursive_remain(a, b));
//	printf("a divide b share is %d\n", recursive_share(a, b));
//	return 0;
//}
//
//int recursive_multiple(int a, int b) {
//	if (b == 0)
//		return 0;
//	else {
//		return a+recursive_multiple(a, b-1);
//	} 
//}
//
//int recursive_remain(int a, int b) {
//	if (a-b< 0)
//		return a;
//	else {
//		return  recursive_remain(a-b, b);
//	}
//}
//
//int recursive_share(int a, int b) {
//	if (a < b)
//		return 0;
//	else {
//		return 1 + recursive_share(a - b, b);
//	}
//}
#include<stdio.h>
#include<string.h>
#define VAL "aaa"
int main() {
	char val[3 + 1];
	strcpy(val, "aaa");
	printf("size of array VAL = %d\n", sizeof(val));
	printf("size of define VAL = %d\n", sizeof(VAL));
	return 0;

}