#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int pc;
	struct node* next;
}node;
typedef struct vertex {
	int name;
	int d;
	int label;
	struct node* incidence;
}vertex;
typedef struct edge {
	int v1, v2;
	int weight;
}edge;
typedef struct graph {
	edge* edges;
	vertex* vertices;
	int size;
	int edgeSize;
	int start;
}graph;
typedef struct cell {
	int index;
	int key;
}cell;
typedef struct queue {
	int rear;
	int front;
	cell arr[10000];
}queue;
void initQueue(queue* q) {
	q->front = 0;
	q->rear = -1;
}
int isEmpty(queue* q) {
	return (q->front == q->rear);
}
void enqueue(queue* q, int i, int d) {
	q->rear++;
	q->arr[q->rear].index = i;
	q->arr[q->rear].key = d;
}
int removequeue(queue* q) {
	for (int i = q->front; i <= q->rear; i++) {
		if ((q->arr[q->front].key > q->arr[i].key&&q->arr[i].key!=-1)|| q->arr[q->front].key==-1) {
			int tmp1;
			tmp1 = q->arr[q->front].key;
			q->arr[q->front].key = q->arr[i].key;
			q->arr[i].key = tmp1;

			tmp1 = q->arr[q->front].index;
			q->arr[q->front].index = q->arr[i].index;
			q->arr[i].index = tmp1;

		}
	}

	int a = q->arr[q->front].index;
	q->front++;
	return a;
}
void replace(queue* q, int z, int dz) {
	for (int i = q->front; i <= q->rear; i++) {
		if (q->arr[i].index == z) {
			q->arr[i].key = dz;
		}
	}
}
node* getnode() {
	node* p = (node*)malloc(sizeof(node));

	p->pc = -1;
	p->next = NULL;

	return p;
}
void putnode(node* p) {
	free(p);
}
void setVertex(graph *g) {
	g->vertices = (vertex*)malloc(sizeof(vertex) * g->size);
	for (int i = 1; i <= g->size; i++) {
		g->vertices[i - 1].name = i;
		g->vertices[i - 1].incidence = getnode();
		g->vertices[i - 1].d = -1;
		g->vertices[i - 1].label = 0;
	}
}
int index(int i) {
	return i - 1;
}
void addFirst(node* H, int i) {
	node* p = getnode();
	p->pc = i;
	p->next = H->next;
	H->next = p;
	return;
}
void insertEdge(graph *g, int a, int b, int w, int i) {
	a = index(a);
	b = index(b);

	g->edges[i].v1 = a;
	g->edges[i].v2 = b;
	g->edges[i].weight = w;

	addFirst(g->vertices[a].incidence, i);
	if (a != b) {
		addFirst(g->vertices[b].incidence, i);
	}
}
void buildGraph(graph *g) {
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	getchar();
	g->size = n;
	g->edgeSize = m;
	g->start = s;
	setVertex(g);
	g->edges = (edge*)malloc(sizeof(edge) * g->edgeSize);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		getchar();
		insertEdge(g, a, b, w, i);
	}

	return;

}
int opposite(graph *g ,int pc, int u) {
	if (g->edges[pc].v1 == u) {
		return g->edges[pc].v2;
	}
	return g->edges[pc].v1;

}
void function(graph* g) {
	g->vertices[index(g->start)].d=0;
	struct queue* q=(queue*)malloc(sizeof(queue));
	initQueue(q);

	for (int i = 0; i < g->size; i++) {
		enqueue(q, i, g->vertices[i].d);
	}
	while (!isEmpty(q)) {
		int u = removequeue(q);
		g->vertices[u].label = 1;
		node* p = g->vertices[u].incidence->next;
		while (p != NULL) {
			int z = opposite(g, p->pc, u);
			if (g->vertices[z].label == 0) {
				if (g->vertices[u].d + g->edges[p->pc].weight < g->vertices[z].d||g->vertices[z].d==-1) {
					g->vertices[z].d = g->vertices[u].d + g->edges[p->pc].weight;
					replace(q, z, g->vertices[z].d);
				}
			}
			p = p->next;
		}
	}
	for (int i = 0; i < g->size; i++) {
		if (i + 1 == g->start||g->vertices[i].d==-1)
			continue;
		printf("%d %d\n", i + 1, g->vertices[i].d);
	}
}
int main() {
	graph* g = (graph*)malloc(sizeof(graph));
	buildGraph(g);
	function(g);
}

//5 7 1
//1 2 1
//1 4 5
//5 1 10
//3 5 3
//4 3 1
//3 1 2
//2 3 2