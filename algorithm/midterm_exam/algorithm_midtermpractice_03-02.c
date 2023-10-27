#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H[101];
int n;
void downHeap(int i) {
	if (2 * i > n)
		return;
	else {
		int greater = 2 * i;
		if (H[greater] < H[2 * i + 1]) {
			greater = 2 * i + 1;
		}
		if (H[greater] > H[i]) {
			int tmp = H[greater];
			H[greater] = H[i];
			H[i] = tmp;
			downHeap(greater);
		}
		return;
	}
}
void rbuildheap(int i) {
	if (i * 2 <= n) {
		rbuildheap(i * 2);
		rbuildheap(i * 2 + 1);
		downHeap(i);
	}
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &H[i]);
		n++;
	}
	//for (int i = num / 2; i >= 1; i--) {
	//	//downHeap(i);
	//}
	rbuildheap(1);
	for (int i = 1; i <= num; i++) {
		printf(" %d", H[i]);
	}
}