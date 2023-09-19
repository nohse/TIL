#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n = 0;
int H[100];
void swap(int i, int j) {
	int tmp;
	tmp = H[i];
	H[i] = H[j];
	H[j] = tmp;
}
void exception() {
	printf("no heap\n");
}
void upHeap(int i) {
	while (i != 1) {
		if (H[i / 2] < H[i]) {
			swap(i, i / 2);
			i = i / 2;
		}
		else
			break;
	}
	return;
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
void insertitem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
	printf("0\n");
}
int removeMax() {
	if (n <= 0) {
		exception();
		return 0;
	}
	int key;
	key = H[1];
	H[1] = H[n];
	H[n] = 0;
	n--;
	downHeap(1);
	printf("%d\n", key);
	return key;
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
int main() {
	char command='a';
	while (command != 'q') {
		scanf("%c", &command);
		if (command == 'i') {
			int key;
			scanf("%d", &key);
			insertitem(key);
		}
		else if (command == 'd') {
			removeMax();
		}
		else if (command == 'p') {
			printHeap();
		}
		getchar();
	}
	return 0;
}