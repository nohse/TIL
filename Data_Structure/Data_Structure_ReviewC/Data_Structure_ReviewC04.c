#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	char arr[101] = {NULL};
	char tmp;
	int i, j;
	gets(arr);
	for (j = 0; j < strlen(arr); j++) {
		printf("%s\n", arr);
		for (i = 0; i < strlen(arr) - 1; i++) {
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}

}