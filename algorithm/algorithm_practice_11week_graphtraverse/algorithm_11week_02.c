#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* next;
	int v;
	int label;
}node;
typedef struct list {
	int level;
	int data;
}list;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->v = NULL;
	p->label = 0;
}
void putnode(node* p) {
	free(p);
}
void insertEdge(node* p, int nodenum) {
	while (p->next != NULL && nodenum > p->next->v) {
		p = p->next;
	}
	node* q = getnode();
	q->v = nodenum;
	q->next = p->next;
	p->next = q;
}
void addLast(int L[][1000], int i, int s) {
	int j = 0;
	while (L[i][j] != -1) {
		j++;
	}
	L[i][j] = s;
}
void BFS1(node* A[], int s) {
	int L[1000][1000];
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			L[i][j] = -1;
		}
	}
	int i = 0, j = 0;
	printf("%d\n", s);
	addLast(L, 0, s);
	A[s]->label = 1;
	while (L[i][j] != -1) {
		int k = 0;
		int v=L[i][k];
		while (v != -1) {
			node* p = A[v]->next;
			while (p != NULL) {
				if (p->label == 0) {
					int w;
					w = p->v;
					if (A[w]->label == 0) {
						p->label = 1;
						A[w]->label = 1;
						addLast(L, i + 1, w);
						printf("%d\n", w);
					}
					else
						p->label = 2;
				}
				p = p->next;
			}
			k++;
			v = L[i][k];
		}
		i++;
	}

}
void BFS(node* A[], int s) {
	BFS1(A, s);
}
int main() {
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	getchar();
	struct node** A = (struct node**)malloc(sizeof(struct node*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		A[i] = getnode();
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		insertEdge(A[a], b);
		if (a != b)
			insertEdge(A[b], a);
	}
	BFS(A, s);
}