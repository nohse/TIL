#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H[101] = {0};
int n;
void downheap(int i) {
	if (2 * i <= n) {
		int greater = 2 * i;
		if (H[greater] < H[2 * i + 1]&&2*i+1<=n)
			greater = 2 * i + 1;
		if (H[greater] > H[i]) {
			int tmp = H[greater];
			H[greater] = H[i];
			H[i] = tmp;
			downheap(greater);
		}
	}
	return;
}
void buildheap() {
	for (int i = n / 2; i >= 1; i--) {
		downheap(i);
	}
}
void inplaceheapsort() {
	int num = n;
	for (int i = num; i > 1; i--) {
		buildheap();
		int tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		n--;
	}

}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &H[i]);
		n++;
	}
	inplaceheapsort();
	for (int i = 1; i <= num; i++) {
		printf(" %d", H[i]);
	}
}