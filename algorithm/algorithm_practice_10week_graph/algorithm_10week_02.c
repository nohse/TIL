#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void makeEdge(int A[][7], int i, int j, int w) {
	if (((i > 6 || i < 1) || (j>6 || j < 1))||(A[i][j]==0&&w==0)) {
		printf("-1\n");
		return;
	}
	A[i][j] = w;
	A[j][i] = w;
}
void find(int A[][7], int num) {
	int j = 1;
	int flag = 0;
	if (num > 6 || num < 1 ) {
		printf("-1\n");
		return;
	}
	while (1) {
		if (A[num][j] == 0) {
			j++;
		}
		else {
			printf(" %d %d", j, A[num][j]);
			flag = 1;
			j++;
		}
		if (j > 7)
			break;
	}
	if (flag == 0)
		printf("-1");
	printf("\n");
}
int main() {
	int A[7][7] = { 0 };
	makeEdge(A, 1, 2, 1);
	makeEdge(A, 1, 3, 1);
	makeEdge(A, 1, 4, 1);
	makeEdge(A, 1, 6, 2);
	makeEdge(A, 2, 1, 1);
	makeEdge(A, 2, 3, 1);
	makeEdge(A, 3, 1, 1);
	makeEdge(A, 3, 2, 1);
	makeEdge(A, 3, 5, 4);
	makeEdge(A, 4, 1, 1);
	makeEdge(A, 5, 3, 4);
	makeEdge(A, 5, 5, 4);
	makeEdge(A, 5, 6, 3);
	makeEdge(A, 6, 1, 2);
	makeEdge(A, 6, 5, 3);

	char cmd = -1;
	while (cmd != 'q') {
		scanf("%c", &cmd);
		if (cmd == 'a') {
			int num;
			scanf("%d", &num);
			getchar();
			find(A, num);
		}
		else if (cmd == 'm') {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			makeEdge(A, a, b, w);
		}
		else if (cmd == 'q') {
			break;
		}
	}
}