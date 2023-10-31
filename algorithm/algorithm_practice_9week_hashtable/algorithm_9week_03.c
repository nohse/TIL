#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int M, N, q;
int firstHash(int x) {
	return x % M;
}
int secondHash(int x) {
	return q - (x % q);
}
void insertItem(int A[], int key) {
	int v = firstHash(key);
	for (int i = 0; i < M; i++) {
		if (A[v] == 0) {
			A[v] = key;
			break;
		}
		printf("C");
		v = (v + secondHash(key)) % M;
	}
	printf("%d\n", v);

}
void searchItem(int A[], int key) {
	int v = firstHash(key);
	while (A[v] != 0) {
		if (A[v] == key) {
			printf("%d %d\n", v, key);
			return;
		}
		v = (v + secondHash(key)) % M;
	}
	printf("-1\n");
}
void printItem(int A[]) {
	for (int i = 0; i < M; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}
int main() {
	scanf("%d %d %d", &M, &N, &q);
	getchar();
	int* A = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		A[i] = 0;
	}
	char select = -1;
	int num = 0;
	while (select != 'e') {
		scanf("%c", &select);
		int key;
		if (select == 'i' && num < N) {
			scanf("%d", &key);
			getchar();
			insertItem(A, key);
			num++;
		}
		else if (select == 's') {
			scanf("%d", &key);
			getchar();
			searchItem(A, key);

		}
		else if (select == 'p') {
			getchar();
			printItem(A);
		}
		else if (select == 'e') {
			printItem(A);
			break;
		}

	}

}