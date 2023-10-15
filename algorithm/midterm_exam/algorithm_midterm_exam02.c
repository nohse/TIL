#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void buildMaxHeap(int H[], int* last, int e) {
	*last = *last + 1;
	int cursor = *last;
	int parent = cursor / 2;
	H[*last] = e;
		while (H[parent] < H[cursor] || cursor == 1) {
			if (cursor != 1) {
				int tmp = H[parent];
				H[parent] = H[cursor];
				H[cursor] = tmp;
				cursor = parent;
				parent = cursor / 2;
			}
			else
				break;
		}
}
void buildMinHeap(int H[], int* last, int e) {
	*last = *last + 1;
	int cursor = *last;
	int parent = cursor / 2;
	H[*last] = e;
		while (H[parent] > H[cursor] || cursor == 1) {
			if (cursor != 1) {
				int tmp = H[parent];
				H[parent] = H[cursor];
				H[cursor] = tmp;
				cursor = parent;
				parent = cursor / 2;
			}
			else
				break;
		}
}
void printHeap(int H[], int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
}
void removeFirst(int H[], int* last) {
	printf("%d ", H[1]);
	H[1] = H[*last];
	H[*last] = 0;
	*last=*last-1;
}
void downMaxHeap(int H[], int i, int last) {
	int greater;
	if (H[i * 2] >= H[i * 2 + 1])
		greater = i * 2;
	else
		greater = i * 2 + 1;
	if (H[greater] > H[i]) {
		int tmp = H[i];
		H[i] = H[greater];
		H[greater] = tmp;
		if (greater >= last)
			return;
		downMaxHeap(H, greater, last);
	}
}
void downMinHeap(int H[], int i, int last) {
	int greater;
	if (H[i * 2] == 0 && H[i * 2 + 1] == 0)
		return;
	if (H[i * 2] <= H[i * 2 + 1]||H[i*2+1]==0)
		greater = i * 2;
	else
		greater = i * 2 + 1;
	if (H[greater] < H[i]) {
		int tmp = H[i];
		H[i] = H[greater];
		H[greater] = tmp;
		if (greater >= last)
			return;
		downMinHeap(H, greater, last);
	}
}
int main() {
	int n;
	int e;
	int maxHeap[101] = {0};
	maxHeap[0] = 9999999;
	int maxLast = 0;
	int minHeap[101] = {0};
	int minLast = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		buildMaxHeap(maxHeap, &maxLast, e);
		buildMinHeap(minHeap, &minLast, e);
	}
	for (int i = 0; i < n; i++) {
		printHeap(maxHeap, n-i);
		printf("\n");
		printHeap(minHeap, n-i);
		printf("\n");
		removeFirst(maxHeap,&maxLast);
		removeFirst(minHeap,&minLast);
		printf("\n");
		downMaxHeap(maxHeap, 1, maxLast);
		downMinHeap(minHeap, 1, minLast);
	}

}