#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char arr[10001];
	int index;
	scanf("%s", arr);
	scanf("%d", &index);
	printf("%c", arr[index-1]);

	return 0;

}