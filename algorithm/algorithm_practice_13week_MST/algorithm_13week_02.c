#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
typedef struct node {
	int pc;
	struct node* next;
}node;
typedef struct edge {
	int v1, v2;
	int weight;
}edge;
typedef struct vertex {
	int name;
	struct node* incidence;
	int label;
	int sack;
}vertex;
typedef struct graph {
	struct vertex* vertices;
	struct edge* edges;
	int size;
	int edgeSize;
}graph;
typedef struct cell {
	int edge;
	int weight;
}cell;
typedef struct two {
	int u;
	int v;
	int pc;
}two;
cell queue[1000];
int front = 0;
int rear = 0;
graph g;
int n, m;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->pc = -1;
	p->next = NULL;

	return p;
}
void putnode(node* p) {
	free(p);
}
void setVertex() {
	g.vertices = (vertex*)malloc(sizeof(vertex) * n);
	for (int i = 1; i <= n; i++) {
		g.vertices[i - 1].name = i;
		g.vertices[i - 1].incidence = getnode();
		g.vertices[i - 1].sack = i;
		g.vertices[i - 1].label = 0;
	}

}
int index(int a) {
	return a - 1;
}
void addFirst(node* H, int i) {
	node* p = getnode();
	p->pc = i;
	p->next = H->next;
	H->next = p;
	return;
}
void insertEdge(int a, int b, int w, int i) {
	a = index(a);
	b = index(b);

	g.edges[i].v1 = a;
	g.edges[i].v2 = b;
	g.edges[i].weight = w;

	addFirst(g.vertices[a].incidence, i);
	if (a != b)
		addFirst(g.vertices[b].incidence, i);

}
void buildGraph() {
	scanf("%d %d", &n, &m);
	getchar();
	g.size = n;
	g.edgeSize = m;
	g.edges = (edge*)malloc(sizeof(edge) * m);
	setVertex();
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		getchar();
		insertEdge(a, b, w, i);
	}

	return;
}
two removeMin() {
	two a;
	for (int i = front + 1; i < rear; i++) {
		if (queue[front].weight > queue[i].weight) {
			int tmpver, tmpkey;
			tmpver = queue[i].edge;
			queue[i].edge = queue[front].edge;
			queue[front].edge = tmpver;

			tmpkey = queue[i].weight;
			queue[i].weight = queue[front].weight;
			queue[front].weight = tmpkey;


		}
	}
	a.u = g.edges[queue[front].edge].v1;
	a.v = g.edges[queue[front].edge].v2;
	a.pc = queue[front].edge;
	front++;
	return a;
}
void merge(int u, int v) {
	int tmp = g.vertices[u].sack;
	int cmp = g.vertices[v].sack;
	for (int i = 0; i < n; i++) {
		if (g.vertices[i].sack == cmp) {
			g.vertices[i].sack = tmp;
		}
	}
}
void KruskalMST() {
	for (int i = 0; i < m; i++) {
		queue[rear].edge = i;
		queue[rear].weight = g.edges[i].weight;
		rear++;
	}
	int T[10000];
	int j = 0;
	int result = 0;
	while (j < n-1) {
		two a;
		a=removeMin();
		if (g.vertices[a.u].sack != g.vertices[a.v].sack) {
			result += g.edges[a.pc].weight;
			printf(" %d", g.edges[a.pc].weight);	
			T[j] = a.pc;
			j++;
			merge(a.u, a.v);
		}
	}
	printf("\n%d\n", result);

}
int main() {

	buildGraph();
	KruskalMST();
}