#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n;
	int num = 0;
	int a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		int cnt = 0;
		for (int j = 1; j <=a; j++) {
			if (a % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2)
			num++;
	}
	printf("%d\n", num);
	return 0;
}