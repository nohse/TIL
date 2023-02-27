#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void my_strcat(char*, char*);
void my_strncat(char*, char*, int);
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, int);
int main() {
	char a[100] = "My first1";
	char b[115] = "My first";
	//my_strcat(a, b);// a 문자열 뒤에 b 문자열 합치기
	//my_strncat(a, b, 2);//a 문자열 뒤에 b 2인덱스 까지 합치기
	//puts(a);
	//printf("result of comapring a and b is %d", my_strcmp(a, b))//a와b 문자열 비교 같을시 0 다를시 -1또는 1
	printf("result of comapring a and b is %d", my_strncmp(a, b, 2));
}
void my_strcat(char a[100], char b[100]) {
	int i, tmp=strlen(a);
	for (i = strlen(a); i < tmp + strlen(b); i++) {
		a[i] = b[i - tmp];
	}
	printf("\n");
}
void my_strncat(char a[100], char b[100], int c) {
	int i, tmp = strlen(a);
	for (i = strlen(a); i < tmp + c; i++) {
		a[i] = b[i - tmp];
	}
	printf("\n");
}
int my_strcmp(char a[1000], char b[1000])
{
	int max;
	int i, flag=0;
	if (strlen(a) > strlen(b))
		max = strlen(a);
	else
		max = strlen(b);

	for (i = 0; i < max; i++) {
		if (a[i] - b[i] < 0) {
			flag = -1;
		}
		else if (a[i] - b[i] > 0)
			flag = 1;
	}
	return flag;
}
int my_strncmp(char a[1000], char b[1000], int c)
{
	int flag = 0;
	for (int i = 0; i < c; i++) {
		if (a[i] - b[i] < 0) {
			flag = -1;
		}
		else if (a[i] - b[i] > 0)
			flag = 1;
	}
	return flag;
}