#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int arr[500001] = { 0 };
	int N;
	int f,r;
	int e;
	scanf("%d", &N);
	if (N == 1) {
		printf("1");
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	f = 0;
	r = N;
	while (f!=r) {
		f = (f + 1) % N;
		if (f == 0)
			f = N;
		arr[f] = 0;
		if (f+1 == r) {
			printf("%d", arr[r]);
			break;
		}
		f = (f + 1) % (N);
		if (f == 0)
			f = N;
		r = (r + 1) % N;
		if (r == 0)
			r = 1;
		arr[r] = arr[f];
		arr[f] = 0;


	}
	return 0;

}