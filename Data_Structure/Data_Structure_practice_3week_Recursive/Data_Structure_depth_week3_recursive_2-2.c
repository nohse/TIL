#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int rpalindrome(char A[], int i, int n) {
	if (i >= n) {
		printf("TRUE\n");
		return;
	}
	else {
		if (A[i] != A[n]) {
			printf("FALSE\n");
			return;
		}
		rpalindrome(A, i + 1, n - 1);
	}
}
int main() {
	char A[100];
	scanf("%s", A);
	int result;
	rpalindrome(A, 0, strlen(A) - 1);
}