#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char c[101];
	int n=0;
	scanf("%s", &c);
	while (c[n] != NULL) {
		n++;
	}
	printf("%d", n);
}