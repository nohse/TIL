#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* next;
	int pc;
}node;
typedef struct vertex {
	int vname;
	int label;
	struct node* incidence;
}vertex;
typedef struct edge {
	int v1, v2;
	int label;
}edge;
typedef struct graph {
	struct vertex* vertices;
	struct edge* edges;
	int size;
	int edgesize;
}graph;

node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->pc = NULL;
	p->next = NULL;

	return p;
}
void putnode(node* p) {
	free(p);
}

void setVertices(graph* g) {
	int vsize = g->size;
	g->vertices = (vertex*)malloc(sizeof(vertex) * vsize);
	for (int i = 0; i <= vsize; i++) {
		g->vertices[i].vname = i;
		g->vertices[i].incidence = getnode();
	}
}
void setEdges(graph* g, int M) {
	int vsize = M;
	g->edges = (edge*)malloc(sizeof(edge) * vsize);
}
int opposite(graph* g, node* p, int a) {
	edge e = g->edges[p->pc];
	if (e.v1 == a)
		return e.v2;
	return e.v1;
}
void insertEdge(graph* g, int a, int b) {
	node* p = g->vertices[a].incidence;
	node* newnode = getnode();
	while ((p->next != NULL)&&opposite(g,p->next,a)<b) {
		p = p->next;
	}
	newnode->pc = g->edgesize;
	g->edges[g->edgesize].v1 = a;
	g->edges[g->edgesize].v2 = b;
	g->edgesize++;
	newnode->next = p->next;
	p->next = newnode;
	return ;
}
void p(graph* g, int vname) {
	node* p = g->vertices[vname].incidence;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", opposite(g, p, vname));
	}
	printf("\n");
	return;
}
void rDFS(graph* g, int v) {
	printf("%d\n", v);
	g->vertices[v].label = 1;
	node* e = g->vertices[v].incidence->next;
	while (e != NULL) {
		if (g->edges[e->pc].label == 0) {
			int w = opposite(g, e, v);
			if (g->vertices[w].label == 0) {
				g->edges[e->pc].label = 1;
				rDFS(g, w);
			}
			else {
				g->edges[e->pc].label = 3;
			}
		}
		e = e->next;
	}
}
void DFS(graph* g, int s) {
	for (int i = 0; i <= g->size; i++) {
		g->vertices[i].label = 0;
	}
	for (int i = 0; i <= g->edgesize; i++) {
		g->edges[i].label = 0;
	}

	rDFS(g, s);
}
int main() {
	int N, M, s;
	graph* g=(graph*)malloc(sizeof(graph));
	scanf("%d %d %d", &N, &M, &s);
	getchar();
	g->size = N;
	g->edgesize = 0;
	setVertices(g);
	setEdges(g, M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		getchar();
		insertEdge(g, a, b);
		if (a != b)
			insertEdge(g, b, a);
	}
	//for (int i = 0; i < 7; i++) {
	//	int j;
	//	scanf("%d", &j);
	//	p(g, j);
	//}
	DFS(g, s);
	return 0;

}