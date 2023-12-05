#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Stack {//stack 구조체 
	int *items;
	int top;
};
void initStack(struct Stack* s, int n) {//stack 초기화 함수
	s->top = -1;
	s->items = (int*)malloc(sizeof(int) * n);
}

int isEmpty(struct Stack* s) {// 스택이 비어있는지 확인하는 함수
	return s->top == -1;
}

void push(struct Stack* s, int value) {	// 스택에 값 추가하는 함수
	s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {// 스택에서 값 제거 후 반환하는 함수
	return s->items[(s->top)--];
}
int top(struct Stack* s) {// 스택에서 값 반환하는 함수
	return s->items[(s->top)];
}
typedef struct node {//node 구조체
	struct node* next;
	int element;
}node;
typedef struct edge {//간선 구조체
	int origin;
	int destination;
}edge;
typedef struct vertex {//정점 구조체
	int name;
	node* outEdges;
	node* inEdges;
	int visit;
}vertex;
typedef struct graph {//그래프 구조체
	struct vertex* vertices;
	struct edge* edges;
	int size;
	int edgeSize;
}graph;
node* getnode() {//node 동적 할당 함수
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->element = -1;

	return p;
}
void putnode(node* p) {//node 동적 할당 해제 함수
	free(p);
}
void addFirst(node* p, int i) {//인접 리스트 첫번째에 추가 함수
	node* q = getnode();
	q->element = i;
	q->next = p->next;
	p->next = q;
	return;

}
int index(int a) {//index 구하는 함수
	return a - 1;
}
void insertDirectedEdge(graph g, int uname, int vname, int i) {//간선 추가 함수
	int u = index(uname);
	int v = index(vname);
	g.edges[i].origin = u;
	g.edges[i].destination = v;
	addFirst(g.vertices[u].outEdges, i);
	addFirst(g.vertices[v].inEdges, i);
}

void insertVertex(graph g, int name, int i) {//정점 추가 함수
	g.vertices[i].name = name;
	g.vertices[i].outEdges = getnode();
	g.vertices[i].inEdges = getnode();
	g.vertices[i].visit = 1;
}
graph buildGraph() {//그래프 빌드 함수
	graph g;
	int n, m;
	scanf("%d %d", &n, &m);//정점과 간선 갯수 입력
	getchar();
	g.vertices = (vertex*)malloc(sizeof(vertex) * n);//정점 갯수 만큼 동적 할당
	g.size = n;
	for (int i = 0; i < n; i++) {//0~n까지 정점 추가
		insertVertex(g, i + 1, i);
	}
	g.edges = (edge*)malloc(sizeof(edge) * m);//간선 갯수 만큼 동적 할당
	g.size = n;
	g.edgeSize = m;
	for (int i = 0; i < m; i++) {//origin, destination 입력 후 간선 추가
		int uname, vname;
		scanf("%d %d", &uname, &vname);
		getchar();
		insertDirectedEdge(g, uname, vname, i);
	}
	return g;
}
int opposite(graph g, node* p) {//간선을 통해 반대 정점 반환 함수
	return g.edges[p->element].destination;
}

void topologicalSortDFS(graph g) {//위상 정렬 함수
	struct Stack stack;
	initStack(&stack, g.size+2);//stack 초기화
	for (int i = 0; i < g.size; i++) {
		if(g.vertices[i].visit==1)//방문하지 않은 정점 stack에 push
			push(&stack, i);
		while (!isEmpty(&stack)) {//스택이 비어있지 않다면 반복
			int v = top(&stack);
			node* p = g.vertices[v].outEdges->next;//v정점 인접 리스트
			int flag = 1;//stack에 푸쉬 했는지 안했는지 확인 flag
			while (p != NULL) {//인접 리스트의 끝이 아닐때 까지 반복
				if (g.vertices[opposite(g, p)].visit == 1) {//방문되지 않은 정점이라면
					push(&stack, opposite(g, p));//stack에 push
					flag = 0;
				}
				p = p->next;
			}
			if (flag == 1) {//방문되지 않은 정점이 없다면
				if (g.vertices[top(&stack)].visit == 1) {//방문한 정점이 아니라면
					printf("%d\n", top(&stack) + 1);//출력
				}
				g.vertices[pop(&stack)].visit = 0;//방문된 노드로 변환
			}
		}
	}
}
void freegraph(graph g) {
	free(g.edges);
	free(g.vertices);
}
int main() {
	graph g;
	g = buildGraph();//그래프 구현
	topologicalSortDFS(g);//위상정렬 함수
	freegraph(g);//메모리 해제 함수
	return 0;
}