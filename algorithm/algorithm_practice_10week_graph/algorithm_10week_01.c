#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* next;
	int v;
	int weight;
}node;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->v = NULL;
	p->weight = NULL;
}
void putnode(node* p) {
	free(p);
}
void makeEdge(node* p, int nodenum, int weight) {
	while (p->next != NULL&&nodenum>p->next->v) {
		p = p->next;
	}
	node* q = getnode();
	q->v = nodenum;
	q->weight = weight;
	q->next = p->next;
	p->next = q;
}
void findnum(node* A) {
	node* p = A->next;
	while (p != NULL) {
		printf(" %d %d", p->v, p->weight);
		p = p->next;
	}
	printf("\n");
}
void deleteedge(node* A[], int a, int b) {
	node* p = A[a];
	int flag = 0;
	while (p != NULL) {
		if (p->next!=NULL&&p->next->v == b) {
			flag=1;
			break;
		}
		p = p->next;
	}
	if (flag == 1) {
		node* q = p->next;
		p->next = q->next;
		putnode(q);
	}
	if (a == b ) {
		if(flag==0)
			printf("-1\n");
		return;
	}
	p = A[b];
	while (p != NULL) {
		if (p->next!=NULL&&p->next->v == a) {
			flag=1;
			break;
		}
		p = p->next;
	}
	if (flag == 0) {
		printf("-1\n");
		return;
	}
	if (flag == 1) {
		node* tmp = p->next;
		p->next = tmp->next;
		putnode(tmp);
	}
}
void newedge(node* A[], int a, int b, int w) {
	node* p = A[a];
	int flag = 0;
	while (p->next != NULL) {
		p = p->next;
		if (p->v == b) {
			flag++;
			break;
		}
	}
	if (flag != 0) {
		p = A[a]->next;
		while (p->v != b) {
			p = p->next;
		}
		p->weight = w;
		p = A[b]->next;
		while (p->v != a) {
			p = p->next;
		}
		p->weight = w;
	}
	else {
		makeEdge(A[a], b, w);
		if(a!=b)
		makeEdge(A[b], a, w);
	}
}
int main() {
	struct node *A[7];
	for (int i = 1; i <= 6; i++) {
		A[i] = getnode();
	}
	makeEdge(A[1], 6, 2);
	makeEdge(A[1], 2, 1);
	makeEdge(A[1], 3, 1);
	makeEdge(A[1], 4, 1);

	
	makeEdge(A[2], 1, 1);
	makeEdge(A[2], 3, 1);

	makeEdge(A[3], 1, 1);
	makeEdge(A[3], 2, 1);
	makeEdge(A[3], 5, 4);

	makeEdge(A[4], 1, 1);

	makeEdge(A[5], 3, 4);
	makeEdge(A[5], 5, 4);
	makeEdge(A[5], 6, 3);

	makeEdge(A[6], 1, 2);
	makeEdge(A[6], 5, 3);

	char cmd = -1;
	while (cmd != 'q') {
		scanf("%c", &cmd);
		if (cmd == 'a') {
			int nodenum;
			scanf("%d", &nodenum);
			getchar();
			if (nodenum > 6||nodenum<1) {
				printf("-1\n");
			}
			else
				findnum(A[nodenum]);
		}
		else if (cmd == 'm') {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			if ((a > 0 && a < 7) && (b > 0 && b < 7)) {
			if (w == 0) {
				deleteedge(A, a, b);
			}
			else
				newedge(A, a, b, w);
			}
			else {
				printf("-1\n");
			}
		}
	}
}