#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H[101] = {0};
int n = 0;
void upheap(int i) {
	if (i == 1) {
		return;
	}
	if (H[i / 2] < H[i]) {
		int tmp = H[i / 2];
		H[i / 2] = H[i];
		H[i] = tmp;
	}
	upheap(i / 2);
}
void insert(int key) {
	n++;
	H[n] = key;
	upheap(n);
	printf("0\n");
}
void downHeap(int i) {
	if (2*i > n)
		return;
	else {
		int greater = 2 * i;
		if (H[greater] < H[2 * i + 1]) {
			greater = 2 * i + 1;
		}
		if (H[greater] > H[i]) {
			int tmp = H[greater];
			H[greater] = H[i];
			H[i] = tmp	;
			downHeap(greater);
		}
		return;
	}
}
void deletekey() {
	int tmp = H[1];
	H[1] = H[n];
	H[n] = 0;
	n--;
	downHeap(1);
	printf("%d\n", tmp);
}
void print() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
int main() {
	char c=0;
	int key;
	while (c != 'q') {
		scanf("%c", &c);
		if (c == 'i') {
			scanf("%d", &key);
			getchar();
			insert(key);
		}
		else if (c == 'p') {
			getchar();
			print();
		}
		else if (c == 'd') {
			getchar();
			deletekey();
		}
		else if (c == 'q') {
			getchar();
			break;
		}
	}
}