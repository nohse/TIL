#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N, X[100], info[99];
	int i,tmp=0, cnt, tmp2;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &info[i]);
	}
	tmp = X[info[0]];
	for (i = 1; i < cnt; i++) {
		tmp2 = X[info[i]];
		X[info[i]] = tmp;
		tmp = tmp2;
		
	}
	for (i = 0; i < N; i++) {
		printf("%d ", X[i]);
	}

	return 0;
}