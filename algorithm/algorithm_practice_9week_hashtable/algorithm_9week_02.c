#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insertItem(int A[], int key, int M) {
	int v = key % M;
	for(int i=0;i<M;i++){
		if (A[v] == 0) {
			A[v] = key;
			break;
		}
		printf("C");
		v=(v+1)%M;
	}
	printf("%d\n", v);

}
void searchItem(int A[], int key, int M) {
	int v = key % M;
	while (A[v] != 0) {
		if (A[v] == key) {
			printf("%d %d\n", v, key);
			return;
		}
		v = (v + 1) % M;
	}
	printf("-1\n");
}
int main() {
	int M,n;
	scanf("%d %d", &M, &n);
	getchar();
	int* A = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		A[i] = 0;
	}
	char select = -1;
	int num = 0;
	while (select!='e') {
		scanf("%c", &select);
		int key;
		if (select == 'i'&&num<n) {
			scanf("%d", &key);
			getchar();
			insertItem(A, key, M);
			num++;
		}
		else if (select == 's') {
			scanf("%d", &key);
			getchar();
			searchItem(A, key, M);

		}
		else if (select == 'e') {
			break;
		}

	}
		
}