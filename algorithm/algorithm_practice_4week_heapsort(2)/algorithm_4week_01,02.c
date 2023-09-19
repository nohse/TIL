#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int H[100];
int n;
int a;
void exception() {
	printf("no heap\n");
	return;
}
void swap(int i, int j) {
	int tmp;
	tmp = H[i];
	H[i] = H[j];
	H[j] = tmp;
}
void downHeap(int i) {
	int left = 2*i;
	int right = 2*i + 1;
	if (left > n)
		return 0;
	int greater = left;
	if (right <= n) {
		if (H[right] > H[greater])
			greater = right;
	}
	if (H[i] >= H[greater])
		return;
	swap(i, greater);
	downHeap(greater);
}
void printHeap() {
	for (int i = 1; i <= a; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
void buildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}
void inPlaceHeapSort() {
	buildHeap();
	for (int i = n; i >= 2; i--) {
		swap(i, 1);
		n--;
		buildHeap();
	}
}
int main() {
	scanf("%d", &n);
	a = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}
	inPlaceHeapSort();
	printHeap();

	return 9;
}