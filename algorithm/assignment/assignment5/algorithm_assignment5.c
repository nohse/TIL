#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Stack {//stack ����ü 
	int *items;
	int top;
};
void initStack(struct Stack* s, int n) {//stack �ʱ�ȭ �Լ�
	s->top = -1;
	s->items = (int*)malloc(sizeof(int) * n);
}

int isEmpty(struct Stack* s) {// ������ ����ִ��� Ȯ���ϴ� �Լ�
	return s->top == -1;
}

void push(struct Stack* s, int value) {	// ���ÿ� �� �߰��ϴ� �Լ�
	s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {// ���ÿ��� �� ���� �� ��ȯ�ϴ� �Լ�
	return s->items[(s->top)--];
}
int top(struct Stack* s) {// ���ÿ��� �� ��ȯ�ϴ� �Լ�
	return s->items[(s->top)];
}
typedef struct node {//node ����ü
	struct node* next;
	int element;
}node;
typedef struct edge {//���� ����ü
	int origin;
	int destination;
}edge;
typedef struct vertex {//���� ����ü
	int name;
	node* outEdges;
	node* inEdges;
	int visit;
}vertex;
typedef struct graph {//�׷��� ����ü
	struct vertex* vertices;
	struct edge* edges;
	int size;
	int edgeSize;
}graph;
node* getnode() {//node ���� �Ҵ� �Լ�
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->element = -1;

	return p;
}
void putnode(node* p) {//node ���� �Ҵ� ���� �Լ�
	free(p);
}
void addFirst(node* p, int i) {//���� ����Ʈ ù��°�� �߰� �Լ�
	node* q = getnode();
	q->element = i;
	q->next = p->next;
	p->next = q;
	return;

}
int index(int a) {//index ���ϴ� �Լ�
	return a - 1;
}
void insertDirectedEdge(graph g, int uname, int vname, int i) {//���� �߰� �Լ�
	int u = index(uname);
	int v = index(vname);
	g.edges[i].origin = u;
	g.edges[i].destination = v;
	addFirst(g.vertices[u].outEdges, i);
	addFirst(g.vertices[v].inEdges, i);
}

void insertVertex(graph g, int name, int i) {//���� �߰� �Լ�
	g.vertices[i].name = name;
	g.vertices[i].outEdges = getnode();
	g.vertices[i].inEdges = getnode();
	g.vertices[i].visit = 1;
}
graph buildGraph() {//�׷��� ���� �Լ�
	graph g;
	int n, m;
	scanf("%d %d", &n, &m);//������ ���� ���� �Է�
	getchar();
	g.vertices = (vertex*)malloc(sizeof(vertex) * n);//���� ���� ��ŭ ���� �Ҵ�
	g.size = n;
	for (int i = 0; i < n; i++) {//0~n���� ���� �߰�
		insertVertex(g, i + 1, i);
	}
	g.edges = (edge*)malloc(sizeof(edge) * m);//���� ���� ��ŭ ���� �Ҵ�
	g.size = n;
	g.edgeSize = m;
	for (int i = 0; i < m; i++) {//origin, destination �Է� �� ���� �߰�
		int uname, vname;
		scanf("%d %d", &uname, &vname);
		getchar();
		insertDirectedEdge(g, uname, vname, i);
	}
	return g;
}
int opposite(graph g, node* p) {//������ ���� �ݴ� ���� ��ȯ �Լ�
	return g.edges[p->element].destination;
}

void topologicalSortDFS(graph g) {//���� ���� �Լ�
	struct Stack stack;
	initStack(&stack, g.size+2);//stack �ʱ�ȭ
	for (int i = 0; i < g.size; i++) {
		if(g.vertices[i].visit==1)//�湮���� ���� ���� stack�� push
			push(&stack, i);
		while (!isEmpty(&stack)) {//������ ������� �ʴٸ� �ݺ�
			int v = top(&stack);
			node* p = g.vertices[v].outEdges->next;//v���� ���� ����Ʈ
			int flag = 1;//stack�� Ǫ�� �ߴ��� ���ߴ��� Ȯ�� flag
			while (p != NULL) {//���� ����Ʈ�� ���� �ƴҶ� ���� �ݺ�
				if (g.vertices[opposite(g, p)].visit == 1) {//�湮���� ���� �����̶��
					push(&stack, opposite(g, p));//stack�� push
					flag = 0;
				}
				p = p->next;
			}
			if (flag == 1) {//�湮���� ���� ������ ���ٸ�
				if (g.vertices[top(&stack)].visit == 1) {//�湮�� ������ �ƴ϶��
					printf("%d\n", top(&stack) + 1);//���
				}
				g.vertices[pop(&stack)].visit = 0;//�湮�� ���� ��ȯ
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
	g = buildGraph();//�׷��� ����
	topologicalSortDFS(g);//�������� �Լ�
	freegraph(g);//�޸� ���� �Լ�
	return 0;
}