#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H[100];
int n;
void exception() {
	printf("no heap\n");
}
void swap(int i, int j) {
	int tmp;
	tmp = H[i];
	H[i] = H[j];
	H[j] = tmp;
}
void downHeap(int i) {
	while (1) {
		if ((H[i] < H[i * 2]) || (H[i] < H[i * 2 + 1])) {
			if (H[i * 2] > H[i * 2 + 1]) {
				swap(i, i * 2);
				i = i * 2;
			}
			else {
				swap(i, i * 2 + 1);
				i = i * 2 + 1;
			}
		}
		else
			break;
	}
}
void printHeap() {
	if (n <= 0) {
		exception();
		return;
	}
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
void buildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}
	buildHeap();
	printHeap();
}