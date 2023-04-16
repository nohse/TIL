#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int recursivegcd1(int a, int b) {
	if (b == 0)
		return a;
	else
		recursivegcd1(b, a % b);
}
int recursivegcd2(int a, int b) {
	int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	else if (a == b)
		return a;
	recursivegcd2(b, a - b);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", recursivegcd1(a, b));
	printf("%d\n", recursivegcd2(a, b));

	return 0;

}