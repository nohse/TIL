#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	struct node* next;
	int element;
}node;
typedef struct edge {
	int* origin;
	int* destination;
}edge;
typedef struct vertex {
	char name;
	node *outEdges;
	node* inEdges;
	int inDegree;

}vertex;
typedef struct graph {
	struct vertex* vertices;
	struct edge* edges;
	int size;
	int edgeSize;
}graph;
graph G;
int n, m;
int topOrder[101];
int queue[101];
int front, rear = 0;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;

	return p;
}
int index(char vname) {
	for (int i = 0; i < n; i++) {
		if (G.vertices[i].name == vname)
			return i;
	}
	return -1;
}
void addFirst(node* H, int i) {
	node* p = getnode();
	p->element = i;
	p->next = H->next;
	H->next = p;
	return;
}
void insertDirectedEdge(char uname, char wname, int i) {
	int u = index(uname);
	int w = index(wname);
	G.edges[i].origin = u;
	G.edges[i].destination = w;
	addFirst(G.vertices[u].outEdges, i);
	addFirst(G.vertices[u].inEdges, i);
	G.vertices[w].inDegree++;
	return;

}
void insertVertex(char name, int i) {
	G.vertices[i].name = name;
	G.vertices[i].inDegree = 0;
	G.vertices[i].outEdges = getnode();
	G.vertices[i].inEdges = getnode();
}
void buildGraph() {
	scanf("%d", &n);
	getchar();
	G.vertices = (vertex*)malloc(sizeof(vertex) * n);
	G.size = n;
	char name;
	for (int i = 0; i < n; i++) {
		scanf("%c", &name);
		insertVertex(name, i);
		getchar();
	}
	scanf("%d", &m);
	getchar();
	G.edges = (edge*)malloc(sizeof(edge) * m);
	G.size = n;
	G.edgeSize = m;
	for (int i = 0; i < m; i++) {
		char uname, vname;
		scanf("%c %c", &uname, &vname);
		getchar();
		insertDirectedEdge(uname, vname, i);
	}
	return;
}
void enqueue(int w) {
	queue[rear] = w;
	rear=((rear+1)%101);
	return;

}
int dequeue() {
	int a = queue[front];
	front++;
	front = front % 101;
	return a;
}
int isEmpty() {
	return (front == rear);
}
void topologicalSort() {
	front = 0;
	rear = 0;
	int in[101] = { 0 };
	int t;
	for (int i = 0; i < n; i++) {
		in[i] = G.vertices[i].inDegree;
		if (in[i] == 0)
			enqueue(i);
	}
	t = 1;
	while (!isEmpty()) {
		int u = dequeue();
		topOrder[t] = u;
		t++;
		node* p = G.vertices[u].outEdges->next;
		while (p != NULL) {
			int w = G.edges[p->element].destination;
			in[w] = in[w] - 1;
			if (in[w] == 0)
				enqueue(w);
			p = p->next;
		}
	}
	if (t <= n)
		topOrder[0] = 0;
	else
		topOrder[0] = 1;
	return;
}
int main() {

	buildGraph();

	topologicalSort();

	if (topOrder[0] == 0)
		printf("0");
	else {	
		for (int i = 1; i <= n; i++) {
			printf("%c ", G.vertices[topOrder[i]].name);
		}
	}

	return 0;
}

