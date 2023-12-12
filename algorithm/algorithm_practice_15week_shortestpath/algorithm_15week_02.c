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
	int origin, destination;
	int weight;
}edge;
typedef struct graph {
	edge* edges;
	vertex* vertices;
	int size;
	int edgeSize;
	int start;
}graph;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));

	p->pc = -1;
	p->next = NULL;

	return p;
}
void putnode(node* p) {
	free(p);
}
void setVertex(graph* g) {
	g->vertices = (vertex*)malloc(sizeof(vertex) * g->size);
	for (int i = 1; i <= g->size; i++) {
		g->vertices[i - 1].name = i;
		g->vertices[i - 1].incidence = getnode();
		g->vertices[i - 1].d = 9999999;
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
void insertEdge(graph* g, int a, int b, int w, int i) {
	a = index(a);
	b = index(b);

	g->edges[i].origin = a;
	g->edges[i].destination = b;
	g->edges[i].weight = w;

	addFirst(g->vertices[a].incidence, i);
}
void buildGraph(graph* g) {
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
int opposite(graph* g, int pc, int u) {
		return g->edges[pc].destination;


}
void function(graph* g) {
	g->vertices[index(g->start)].d = 0;
	for (int i = 0; i < g->size; i++){
		for (int j = 0; j < g->edgeSize; j++) {
			int u = g->edges[j].origin;
			int z = g->edges[j].destination;
			if (g->edges[j].weight + g->vertices[u].d < g->vertices[z].d) {
				g->vertices[z].d = g->edges[j].weight + g->vertices[u].d;
			}
		}
	}
	for (int i = 0; i < g->size; i++) {
		if (i + 1 == g->start || g->vertices[i].d >=99999)
			continue;
		printf("%d %d\n", i + 1, g->vertices[i].d);
	}
}
int main() {
	graph* g = (graph*)malloc(sizeof(graph));
	buildGraph(g);
	function(g);
}
