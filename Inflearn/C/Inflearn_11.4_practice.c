#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	//char small_array[5];
	//puts("Enter long string : ");
	//while (fgets(small_array, 5, stdin) != NULL && small_array[0]!='\n')//file 문자열 입력
	//{
	//	fputs(small_array, stdout);
	//}
	char str1[6], str2[6];
	int count = scanf("%5s %5s", str1, str2);
	printf("%s %s", str1, str2);


}