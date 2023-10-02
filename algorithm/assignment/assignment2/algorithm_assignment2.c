#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {// node 구조체
	struct node* left;
	struct node* right;
	struct node* parent;
	int key;

}node;
typedef struct QueueNode {// quenode 구조체
	node* data;
	struct QueueNode* next;
} QueueNode;
typedef struct queue {//level 순회를 위한 que 구조체
	QueueNode* front;
	QueueNode* rear;
}Queue;
Queue* getQueue() {//que 선언 함수
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}
void enqueue(Queue* queue, node* data) {//queue 삽입 함수
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->rear == NULL) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}
node* dequeue(Queue* queue) {//queue 출력 함수
	if (queue->front == NULL) {
		return NULL;
	}

	QueueNode* temp = queue->front;
	node* data = temp->data;

	queue->front = queue->front->next;
	free(temp);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	return data;
}
node* getnode() {//node 선언 함수
	struct node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	p->key = -2147483640;
	return p;
}
int isRoot(node* p) {
	return (p->parent) == NULL;
}
int isRightChild(node* p) {
	return ((!isRoot(p)&&p->parent->right == p));
}
int isLeftChild(node* p) {
	return ((!isRoot(p)&&p->parent->left == p));
}
int isInternal(node* p) {
	return ((p->left != NULL) && (p->right != NULL));
}
int isEmpty(node* root) {
	return (root->key == -2147483640);
}
void putnode(node* p) {
	free(p);
}

node* findLast(struct Node* root) {//마지막 노드 탐색 함수
	if (root == NULL)
		return NULL;

	struct Node* queue[1000]; // 큐를 사용하여 마지막 노드를 찾기
	int front = -1, rear = -1;
	queue[++rear] = root;

	while (front != rear) {
		struct node* currentNode = queue[++front];

		if (isInternal(currentNode->left))
			queue[++rear] = currentNode->left;

		if (isInternal(currentNode->right))
			queue[++rear] = currentNode->right;
	}
	return queue[rear];
}
node* advanceLast(node* last) {//마지막 노드에서 다음 노드로 전진 함수
	node* p = last;
	while (isRightChild(p)) {
		p = p->parent;
	}
	if (isLeftChild(p)) {
		p = p->parent->right;
	}
	while (isInternal(p)) {
			p = p->left;
	}

	return p;
}
void expandExternal(node* z) {//외부노드 확장 함수
	node* l = getnode();
	node* r = getnode();
	l->parent = z;
	r->parent = z;
	z->left = l;
	z->right = r;
	return;
}
void upHeap(node* v) {
	if (isRoot(v))
		return;
	if ((v->key) <= (v->parent->key))
		return;
	int tmp = v->parent->key;
	v->parent->key = v->key;
	v->key = tmp;
	upHeap(v->parent);
			
}
void downHeap(node* root) {
	if ((!isInternal(root->left)) && (!isInternal(root->right)))
		return;
	node* biger = root->left;
	if (isInternal(root->right)) {
		if (root->right->key > biger->key) {
			biger = root->right;
		}
	}
	if (root->key >= biger->key)
		return;
	int tmp = root->key;
	root->key = biger->key;
	biger->key = tmp;
	downHeap(biger);
}
void insertitem(node * root, int key) {//힙 삽입 함수
	if (isEmpty(root)) {
		root->key = key;
		expandExternal(root);
		printf("0\n");
		return;
	}
	node* last = findLast(root);
	node* z = getnode();
	z = advanceLast(last);
	z->key = key;
	expandExternal(z);
	upHeap(z);
	printf("0\n");
}
void reduceExternal(node* z) {// 외부노드 감소 함수
	node* w = z->parent;
	node* g = w->parent;
	if (g == NULL) {
		putnode(w);
	}
	if (g->left == w) {
		g->left = getnode();
		g->left->parent = g;
	}
	else {
		g->right = getnode();
		g->right->parent = g;
	}
	putnode(w->left);
	putnode(w->right);
}
int removeMax(node* root) {//최대 힙 삭제
	int k = root->key;

	node* w = findLast(root);
	root->key = w->key;
	if (w != root) {
		reduceExternal(w->right);
		downHeap(root);
	}
	else {
		root->key = -2147483640;
	}
	if (k == -2147483640) {
		printf("wrong exception\n");
	}
	else
	printf("%d\n", k);
	return k;
}

void printHeap (node* root) {// 전체 힙 출력 레벨 순회(큐 사용)
	if (root == NULL) {
		return;
	}

	Queue* queue = getQueue();
	enqueue(queue, root);

	while (queue->front != NULL) {
		node* current = dequeue(queue);
		if(current->key!=-2147483640)
		printf("%d ", current->key);
		if (current->left != NULL) {
				enqueue(queue, current->left);
			}

		if (current->right != NULL) {
				enqueue(queue, current->right);
			}
	}

	free(queue);
}
void freeHeap(node* root) {// 힙 동적 할당 해제 함수
	if (root == NULL) {
		return;
	}

	// 왼쪽 서브트리 해제
	freeHeap(root->left);

	// 오른쪽 서브트리 해제
	freeHeap(root->right);

	// 현재 노드 해제
	putnode(root);
}
int main() {
	struct node* root = getnode();
	root->parent = NULL;
	char command = 'a';
	while (command != 'q') {
		scanf("%c", &command);
		if (command == 'i') {
			int key;
			scanf("%d", &key);
			insertitem(root, key);
		}
		else if (command == 'd') {
			removeMax(root);
		}
		else if (command == 'p') {
			printHeap(root);
			printf("\n");
		}
		getchar();
	}
	freeHeap(root);
	return 0;
}