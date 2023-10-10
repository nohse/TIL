#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a, b, n;
	int mid;
	char cmd;
	scanf("%d %d %d", &a, &b, &n);
	getchar();
	for (int i = 0; i < n; i++) {
		mid = (a + b) / 2;
		scanf("%c", &cmd);
		if (cmd == 'Y') {
			a = mid + 1;
		}
		else if (cmd == 'N') {
			b = mid;
		}
	}
	printf("%d", a);

	return 0;
}