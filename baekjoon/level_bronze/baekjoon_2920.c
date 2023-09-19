#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main() {
	int a[8];
	int flag = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 7; i++) {
		if (a[i] + 1 == a[i + 1])
			flag = 1;
		else if (a[i] - 1 == a[i + 1])
			flag = 2;
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 0)
		printf("mixed\n");
	else if (flag == 1)
		printf("ascending\n");
	else if (flag == 2)
		printf("descending\n");

	return 0;
}