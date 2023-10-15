#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int cnt = 0;
int rcalc(int n) {
	cnt++;
	if (n == 0)
		return 1;
	else {
		return rcalc((n / 2)) + rcalc((n / 3));
	}
}
int main() {
	int n;
	int sum = 0;
	scanf("%d", &n);
	printf("%d %d",rcalc(n),cnt);

	return 0;
}
