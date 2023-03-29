#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int X[100];
	int N, i, a,b, cnt, tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &X[i]);
	}
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%d %d", &a, &b);
		while (a < b) {
			tmp = X[a];
			X[a] = X[b];
			X[b] = tmp;
			a++;
			b--;
		}
	}
	for (i = 0; i < N; i ++ ) {
		printf("%d ", X[i]);
	}

	return 0;

}