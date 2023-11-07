#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int all = 8;
typedef struct node {
	int num;
	struct node *next;
}node;
typedef struct vertices {
	int nodenum;
	struct node *head;
}vertices;
typedef struct edges {
	int from;
	int to;
	int edgenum;
}edges;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->num = NULL;
}
void makeEdge(vertices *A, int i) {
	struct node* p = A->head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = getnode();
	p->next->num = i;
}
int findnum(edges* edgeArray, int num) {
	if (edgeArray->to != num)
		return edgeArray->to;
	return edgeArray->from;
}
void find(vertices* A, int num, edges *edgeArray) {
	if (num > 6) {
		printf("-1\n");
		return;
	}
	node* p = A[num].head;
	while (p->next != NULL) {
		p = p->next;
		if(findnum(&edgeArray[p->num], num)!=0&& edgeArray[p->num].edgenum!=0)
			printf(" %d %d", findnum(&edgeArray[p->num],num), edgeArray[p->num].edgenum);
	}
	printf("\n");
}
void deleteedge(vertices *A, edges *edgeArray, int a, int b) {
	if (a > 6 || b > 6) {
		printf("-1\n");
		return;
	}
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	for (int i = 1; i <= all; i++){
		if (a == edgeArray[i].to && b == edgeArray[i].from) {
			edgeArray[i].to == 0;
			edgeArray[i].from == 0;
			break;
		}
	}
}
void makesedge(vertices *A, edges *edgeArray, int a, int b, int w) {
	if (w == 0) {
		deleteedge(A, edgeArray, a, b);
	}
}
int main() {
	struct vertices A[6];
	for (int i = 1; i <= 6; i++) {
		A[i].nodenum = i;
		A[i].head = getnode();
	}
	struct edges edgeArray[121];
	edgeArray[1].from = 1;
	edgeArray[1].to = 2;
	edgeArray[1].edgenum = 1;
	makeEdge(&A[1], 1);
	makeEdge(&A[2], 1);


	edgeArray[2].from = 1;
	edgeArray[2].to = 3;
	edgeArray[2].edgenum = 1;
	makeEdge(&A[1], 2);
	makeEdge(&A[3], 2);


	edgeArray[3].from = 1;
	edgeArray[3].to = 4;
	edgeArray[3].edgenum = 1;
	makeEdge(&A[1], 3);
	makeEdge(&A[4], 3);

	edgeArray[4].from = 1;
	edgeArray[4].to = 6;
	edgeArray[4].edgenum = 2;
	makeEdge(&A[1], 4);
	makeEdge(&A[6], 4);

	edgeArray[5].from = 2;
	edgeArray[5].to = 3;
	edgeArray[5].edgenum = 1;
	makeEdge(&A[2], 5);
	makeEdge(&A[3], 5);

	edgeArray[6].from = 3;
	edgeArray[6].to = 5;
	edgeArray[6].edgenum = 4;
	makeEdge(&A[3], 6);
	makeEdge(&A[5], 6);

	edgeArray[7].from = 5;
	edgeArray[7].to = 5;
	edgeArray[7].edgenum = 4;
	makeEdge(&A[5], 7);

	edgeArray[8].from = 5;
	edgeArray[8].to = 6;
	edgeArray[8].edgenum = 3;
	makeEdge(&A[5], 8);
	makeEdge(&A[6], 8);

	char cmd = -1;
	while (cmd != 'q') {
		scanf("%c", &cmd);
		int nodenum;
		if (cmd == 'a') {
			scanf("%d", &nodenum);
			getchar();
			find(A, nodenum, edgeArray);
		}
		else if (cmd == 'm') {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			makesedge(A, edgeArray, a, b, w);
			
		}
		else if (cmd == 'q')
			break;
	}
	return 0;
}