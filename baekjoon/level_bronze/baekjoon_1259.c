#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	char arr[99999];
	int i;
	while (scanf("%s", arr) && arr[0] != '0') {
		getchar();
		int check = 1;
		for (int i = 0; i <= (strlen(arr) / 2); i++) {
			if (arr[i] != arr[strlen(arr) - i-1])
				check = 0;
		}
		if (check == 1)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}