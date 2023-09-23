#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int mult5, mult25, mult125;
	mult5 = N / 5;
	mult25 = N / 25;
	mult125 = N / 125;

	printf("%d\n", mult5+mult25+mult125);
	return 0;
}