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
	int d, p;
	int label;
}vertex;
typedef struct graph {
	struct vertex* vertices;
	struct edge* edges;
	int size;
	int edgeSize;
}graph;
typedef struct cell {
	int vertex;
	int key;
}cell;
graph g;
int n, m;
cell queue[10000];
int front = 0;
int rear = 0;
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
	g.vertices = (vertex*)malloc(sizeof(vertex)*n);
	for (int i = 1; i <= n; i++) {
		g.vertices[i - 1].name = i;
		g.vertices[i - 1].incidence = getnode();
		g.vertices[i - 1].d = 999999;
		g.vertices[i - 1].p = -1;
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
		insertEdge(a, b, w ,i);
	}

	return;
}
void enqueue(int i) {
	queue[rear].vertex = i;
	queue[rear].key = g.vertices[i].d;
	rear++;
}
void initQueue() {
	for (int i = 0; i < n; i++) {
		enqueue(i);
	}
}
int isEmpty() {
	return front == rear;
}
int result = 0;
int removeMin() {
	for (int i = front+1; i < rear; i++) {
		if (queue[front].key > queue[i].key) {
			int tmpver, tmpkey;
			tmpver = queue[i].vertex;
			queue[i].vertex = queue[front].vertex;
			queue[front].vertex = tmpver;

			tmpkey = queue[i].key;
			queue[i].key = queue[front].key;
			queue[front].key = tmpkey;


		}
	}
	result += queue[front].key;
	int a = queue[front].vertex;
	front++;
	return a;
}
int opposite(node* p, int u) {
	if (g.edges[p->pc].v1 != u)
		return g.edges[p->pc].v1;
	return g.edges[p->pc].v2;

}
void replaceKey(int z, int key) {
	for (int i = front; i < rear; i++) {
		if (queue[i].vertex == z) {
			queue[i].key = key;
		}
	}
}
int find(int u) {
	for (int i = front; i < rear; i++) {
		if (queue[i].vertex == u)
			return queue[i].key;
	}
}
void PrimJarnikMST() {
	vertex s= g.vertices[0];
	g.vertices[0].d = 0;
	initQueue();
	while (!isEmpty()) {
		int u = removeMin();
		printf(" %d", u+1);
		g.vertices[u].label = 1;
		node* p = g.vertices[u].incidence->next;
		while (p != NULL) {
			int z = opposite(p, u);
			int w = g.edges[p->pc].weight;
			if ((g.vertices[z].label == 0) && (w < g.vertices[z].d)) {
				g.vertices[z].d = w;
				replaceKey(z, w);
			}
			p = p->next;

		}
	}
	printf("\n%d\n", result);

}
int main() {

	buildGraph();
	PrimJarnikMST();
}