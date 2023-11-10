#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {//node 구조체
	struct node* left;
	struct node* right;
	struct node* parent;
	int height;
	int key;
} node;

node* getnode() {//node 동적 할당
	node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	p->height = 0;//첫 동적 할당 시 높이 0으로 초기화
	p->key = NULL;

	return p;
}
int isExternal(node* p) {//노드가 외부노드인지 확인 함수
	return(p->left == NULL && p->right == NULL);
}
int isInternal(node* p) {//노드가 내부노드인지 확인 함수
	return(p->left != NULL || p->right != NULL);
}
int isRoot(node* p) {//노드가 루트 노드인지 확인 함수
	return(p->parent == NULL);
}
void putnode(node* p) {//동적 할당 해제 함수
	free(p);
}
node* treeSearch(node* v, int k) {//트리 이진 탐색 함수
	if (isExternal(v))//외부 노드시 함수 종료
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key) {//키 값이 더 작을시 왼쪽 노드로 재귀 트리 탐색
		return treeSearch(v->left, k);
	}
	else//키 값이 더 클 시 오른쪽 노드로 재귀 트리 탐색
		return treeSearch(v->right, k);
}
void expandExternal(node* w, node* root) {//외부 노드 확장 함수
	node* a = getnode();//node a 동적 할당
	node* b = getnode();//node b 동적 할당
	w->right = a;//부모 자식관계 연결
	a->parent = w;
	w->left = b;
	b->parent = w;
	if (w != root) {//node w의 부모 노드 연결
		node* parent;
		node* cursor = root;
		while (1) {
			if (cursor->left->key == w->key || cursor->right->key == w->key) {
				parent = cursor;
				break;
			}
			else if (cursor->key > w->key) {
				cursor = cursor->left;
			}
			else
				cursor = cursor->right;
		}
		w->parent = parent;
	}
}
node* restructure(node** x, node** y, node** z) {//재개조 함수
	node* a;//중위 순회로 사용할 node 선언
	node* b;
	node* c;
	node* T0 = NULL;//중위 순회 노드들의 부트리 선언
	node* T1 = NULL;
	node* T2 = NULL;
	node* T3 = NULL;

	// 여기서 x, y, z를 직접 업데이트
	if ((*x)->key > (*y)->key && (*x)->key > (*z)->key) {//a,b,c 노드 초기화 (x가 가장 클경우)
		c = *x;
		if ((*y)->key > (*z)->key) {
			b = *y;
			a = *z;
		}
		else {
			a = *y;
			b = *z;
		}
	}
	else if ((*y)->key > (*x)->key && (*y)->key > (*z)->key) {//a,b,c 노드 초기화 (y가 가장 클경우)
		c = *y;
		if ((*x)->key > (*z)->key) {
			b = *x;
			a = *z;
		}
		else {
			a = *x;
			b = *z;
		}
	}
	else {//a,b,c 노드 초기화 (z가 가장 클경우)
		c = *z;
		if ((*x)->key > (*y)->key) {
			b = *x;
			a = *y;
		}
		else {
			b = *y;
			a = *x;
		}
	}
	if (a == *z && b == *y && c == *x) {// 각 abc별 부트리 초기화 (단일 회전)
		T0 = a->left;
		T1 = b->left;
		T2 = c->left;
		T3 = c->right;
	}
	else if (a == *x && b == *y && c == *z) {// 각 abc별 부트리 초기화 (단일 회전)
		T0 = a->left;
		T1 = a->right;
		T2 = b->right;
		T3 = c->right;
	}
	else if (a == *z && b == *x && c == *y) {// 각 abc별 부트리 초기화 (이중 회전)
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	else if (a == *y && b == *x && c == *z) {// 각 abc별 부트리 초기화 (이중 회전)
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	if (!isRoot(*z) && (*z)->parent->left == *z) {
		(*z)->parent->left = b;
	}
	else if (!isRoot(*z) && (*z)->parent->right == *z) {
		(*z)->parent->right = b;
	}
	b->parent = (*z)->parent;//회전 하며 부트리들 연결
	a->left = T0;
	a->right = T1;
	T0->parent = a;
	T1->parent = a;
	c->left = T2;
	c->right = T3;
	T2->parent = c;
	T3->parent = c;
	b->left = a;
	b->right = c;
	a->parent = b;
	c->parent = b;
	updateHeight(a);//a 높이 업데이트
	updateHeight(c);//c 높이 업데이트
	updateHeight(b);//b 높이 업데이트
	return b;
}
int updateHeight(node* w) {//높이 업데이트 함수
	int h = w->left->height + 1;
	if (h < w->right->height + 1) {//h를 자식 노드 중 최댓값+1으로 선언
		h = w->right->height + 1;
	}
	if (h != w->height) {//같지 않을시 w의 높이에 h값 대입
		w->height = h;
		return 1;//참 반환
	}
	return 0;//거짓 반환
}
int isBalanced(node* w) {//균형 체크 함수
	if (w->left->height > w->right->height) {//양 자식 높이의 차 절대값이 2보다 작을시 참 아닐 시 거짓 반환
		return (w->left->height - w->right->height) < 2;
	}
	return (w->right->height - w->left->height) < 2;
}
void searchAndFixAfterInsertion(node* w) {//삽입후 탐색과수리 함수
	w->left->height = 0;
	w->right->height = 0;
	w->height = 1;
	if (isRoot(w))//w가 루트 노드일시 함수 종료
		return;
	node* z = w->parent;//z는 w의 부모 노드
	node* y = NULL;
	node* x = NULL;

	while (updateHeight(z) && isBalanced(z)) {//루트로 가며 처음 만나는 불균형 노드를 z
		if (isRoot(z))
			return;
		z = z->parent;
	}

	if (isBalanced(z))
		return;
	if (z->left->height > z->right->height)//z의 높은 자식을 y
		y = z->left;
	else
		y = z->right;
	if (y->left->height > y->right->height)//y의 높은 자식을 x
		x = y->left;
	else
		x = y->right;

	restructure(&x, &y, &z);//재개조
	return;
}
node* insertItem(node* root, int k) {//아이템 삽입 함수
	node* w = treeSearch(root, k);//이진 탐색 트리
	if (isInternal(w))
		return;
	else {
		w->key = k;//w노드에 key set
		expandExternal(w, root);//외부 노드 확장 함수
		searchAndFixAfterInsertion(w);
		while (!isRoot(w)) {//w를 다시 root노드로 대입
			w = w->parent;
		}
		return w;//root노드 반환
	}
}
int findElement(node* root, int k) {//이진 탐색
	node* w = treeSearch(root, k);
	if (isExternal(w))
		return-1;
	else
		return w->key;
}
void printAvlTree(node* w) {//avl트리 출력 함수
	if (isInternal(w)) {
		printf(" %d", w->key);
		printAvlTree(w->left);
		printAvlTree(w->right);
	}
}
void freeTree(node* w) {//트리 동적 할당 메모리 해제 함수
	if (w != NULL) {
		freeTree(w->left);
		freeTree(w->right);
		putnode(w);
	}
}
node* inOrderSucc(node* w) {//w의 중위순회 node 반환 함수
	w = w->right;//w의 자식 노드
	if (isExternal(w)) {
		return NULL;
	}
	while (isInternal(w->left)) {
		w = w->left;
	}

	return w;
}
node* sibling(node* w) {//w의 형제 노드 반환 함수
	if (isRoot(w))
		return;
	if (w->parent->left == w)
		return w->parent->right;
	else
		return w->parent->left;
}
node* reduceExternal(node** root, node* z) {//외부노드의 축소 함수
	node* w = z->parent;//w를 z의 부모노드로 초기화
	node* zs = sibling(z);//zs를 z의 형제 노드로 초기화
	if (isRoot(w)) {//w가 루트 노드라면 zs를 루트 노드로 초기화
		*root = zs;
		zs->parent = NULL;
	}
	else {
		node* g = w->parent;//증조부모 초기화
		zs->parent = g;//zs의 부모를 증조부모로 대입
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	}
	putnode(z);//z 노드 동적할당 메모리 해제
	putnode(w);//w 노드 동적할당 메모리 해제
	return zs;//zs 노드 반환
}
void searchAndFixAfterRemoval(node* z) {//제거후 탐색 및 수리 함수
	node* x;
	node* y;
	while (updateHeight(z) && isBalanced(z)) {//루트로 가며 가장 처음 만나는 불균형 노드 z
		if (isRoot(z))
			return;
		z = z->parent;
	}
	if (isBalanced(z))//균형이 잡혀 있다면 함수 종료
		return;

	if (z->left->height > z->right->height)//z의 높은 자식 y
		y = z->left;
	else
		y = z->right;

	if (y->left->height > y->right->height)//y의 높은 자식 x
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;
	else {//높이가 같을시 y와 같은 쪽 선택
		if (z->left == y)
			x = y->left;
		else
			x = y->right;
	}
	node* b = restructure(&x, &y, &z);//재개조 함수 수행
	if (isRoot(b))//b가 루트 노드라면 함수 종료
		return;
	searchAndFixAfterRemoval(b->parent);//b의 부모로부터 루트까지 수행하며 균형을 잃은 노드를 재귀적으로 수리
}
node* removeElement(node* root, int k) {//key값에 맞는 노드 제거 함수
	node* w = treeSearch(root, k);//이진 탐색
	if (isExternal(w)) {//key에 해당하는 node가 없을 시
		printf("X\n");//X출력
		return root;//root 반환
	}

	node* z = w->left;//z를 w의 왼쪽 자식으로 초기화
	node* zs;

	if (!isExternal(z)) {//z가 외부노드가 아니라면 z에 w의 오른쪽 자식으로 대입
		z = w->right;
	}

	if (isExternal(z)) {//z가 외부 노드일시 z노드 축소
		zs = reduceExternal(&root, z);
	}
	else {//내부 노드일 시
		node* y = inOrderSucc(w);//y를 w의 다음 중위순회자로 초기화
		z = y->left;//z를 y의 왼쪽 자식으로 초기화
		w->key = y->key;//w node에 y키 값으로 셋
		zs = reduceExternal(root, z);//z 노드 축소
	}
	if(!isRoot(zs))//zs 노드가 루트가 아니라면 
		searchAndFixAfterRemoval(zs->parent);
	printf("%d\n", k);//제거된 key값 출력
	while (!isRoot(zs)) {//zs를 다시 루트 노드로 대입
		zs = zs->parent;
	}
	return zs;//루트 노드 반환
}
int main() {
	struct node* root = getnode();//루트 노드 동적 할당
	char cmd = -1;//명령어 입력 -1로 초기화
	while (cmd != 'q') {
		scanf("%c", &cmd);
		int key;
		if (cmd == 'i') {//i 입력시 키 삽입 함수 수행
			scanf("%d", &key);
			getchar();
			root = insertItem(root, key);
		}
		else if (cmd == 's') {//s 입력시 키 탐색 함수 수행
			scanf("%d", &key);
			getchar();
			int i = findElement(root, key);
			if (i == -1) {//해당 키가 존재하지 않을 시 X출력
				printf("X\n");
			}
			else
				printf("%d\n", i);
		}
		else if (cmd == 'd') {
			scanf("%d", &key);
			getchar();
			root  = removeElement(root, key);

		}
		else if (cmd == 'p') {//p 입력시 tree 출력 함수 수행
			getchar();
			printAvlTree(root);
			printf("\n");
		}
	}
	freeTree(root);//동적 할당 메모리 해제 함수
	return 0;
}