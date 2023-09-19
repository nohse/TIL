#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[1000001];

int main() {


	int res = 1;

	scanf("%[^\n]", s);

	if (strlen(s) == 1 && s[0] == ' ') {
		printf("0");
		return 0;
	}

	for (int i = 1; i < strlen(s) - 1; i++) {
		if (s[i] == ' ') res++;
	}

	printf("%d", res);

	return 0;
}