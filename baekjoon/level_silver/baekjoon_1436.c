#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check(int num) {
	int arr[10];
	int i = 0;
	while (num!=0) {
		arr[i] = num % 10;
		num = num / 10;
		i++;
	}
	i = 0;
	while (arr[i] <= 9 && arr[i] >= 0) {
		if (arr[i] == 6 && arr[i + 1] == 6 && arr[i+2] == 6)
			return 1;
		i++;
	}
	return 0;
}
int main() {
	int num=0;
	int n, cnt=0;
	scanf("%d", &n);
	while (cnt != n) {
		num++;
		if (check(num))
			cnt++;
		if (cnt == n) {
			printf("%d", num);
			break;
		}
	}
	return 0;
}