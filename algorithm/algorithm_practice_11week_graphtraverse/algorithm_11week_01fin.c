#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* next;
	int v;
	int label;
}node;
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
void rDFS(node* A[], int s) {
	printf("%d\n", s);
	A[s]->label = 1;
	node* p = A[s]->next;
	while (p != NULL) {
		if (p->label == 0) {
			int w;
			w = p->v;
			if (A[w]->label == 0) {
				p->label = 1;
				rDFS(A, w);
			}
			else
				p->label = 2;
		}
		p = p->next;
	}
}
void DFS(node* A[], int s) {
	rDFS(A, s);
}
int main() {
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	getchar();
	struct node** A = (struct node**)malloc(sizeof(struct node*) * (n+1));
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
	DFS(A, s);
}