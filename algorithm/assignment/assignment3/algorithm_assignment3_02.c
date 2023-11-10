#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {//node ����ü
	struct node* left;
	struct node* right;
	struct node* parent;
	int height;
	int key;
} node;

node* getnode() {//node ���� �Ҵ�
	node* p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	p->height = 0;//ù ���� �Ҵ� �� ���� 0���� �ʱ�ȭ
	p->key = NULL;

	return p;
}
int isExternal(node* p) {//��尡 �ܺγ������ Ȯ�� �Լ�
	return(p->left == NULL && p->right == NULL);
}
int isInternal(node* p) {//��尡 ���γ������ Ȯ�� �Լ�
	return(p->left != NULL || p->right != NULL);
}
int isRoot(node* p) {//��尡 ��Ʈ ������� Ȯ�� �Լ�
	return(p->parent == NULL);
}
void putnode(node* p) {//���� �Ҵ� ���� �Լ�
	free(p);
}
node* treeSearch(node* v, int k) {//Ʈ�� ���� Ž�� �Լ�
	if (isExternal(v))//�ܺ� ���� �Լ� ����
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key) {//Ű ���� �� ������ ���� ���� ��� Ʈ�� Ž��
		return treeSearch(v->left, k);
	}
	else//Ű ���� �� Ŭ �� ������ ���� ��� Ʈ�� Ž��
		return treeSearch(v->right, k);
}
void expandExternal(node* w, node* root) {//�ܺ� ��� Ȯ�� �Լ�
	node* a = getnode();//node a ���� �Ҵ�
	node* b = getnode();//node b ���� �Ҵ�
	w->right = a;//�θ� �ڽİ��� ����
	a->parent = w;
	w->left = b;
	b->parent = w;
	if (w != root) {//node w�� �θ� ��� ����
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
node* restructure(node** x, node** y, node** z) {//�簳�� �Լ�
	node* a;//���� ��ȸ�� ����� node ����
	node* b;
	node* c;
	node* T0 = NULL;//���� ��ȸ ������ ��Ʈ�� ����
	node* T1 = NULL;
	node* T2 = NULL;
	node* T3 = NULL;

	// ���⼭ x, y, z�� ���� ������Ʈ
	if ((*x)->key > (*y)->key && (*x)->key > (*z)->key) {//a,b,c ��� �ʱ�ȭ (x�� ���� Ŭ���)
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
	else if ((*y)->key > (*x)->key && (*y)->key > (*z)->key) {//a,b,c ��� �ʱ�ȭ (y�� ���� Ŭ���)
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
	else {//a,b,c ��� �ʱ�ȭ (z�� ���� Ŭ���)
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
	if (a == *z && b == *y && c == *x) {// �� abc�� ��Ʈ�� �ʱ�ȭ (���� ȸ��)
		T0 = a->left;
		T1 = b->left;
		T2 = c->left;
		T3 = c->right;
	}
	else if (a == *x && b == *y && c == *z) {// �� abc�� ��Ʈ�� �ʱ�ȭ (���� ȸ��)
		T0 = a->left;
		T1 = a->right;
		T2 = b->right;
		T3 = c->right;
	}
	else if (a == *z && b == *x && c == *y) {// �� abc�� ��Ʈ�� �ʱ�ȭ (���� ȸ��)
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	else if (a == *y && b == *x && c == *z) {// �� abc�� ��Ʈ�� �ʱ�ȭ (���� ȸ��)
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
	b->parent = (*z)->parent;//ȸ�� �ϸ� ��Ʈ���� ����
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
	updateHeight(a);//a ���� ������Ʈ
	updateHeight(c);//c ���� ������Ʈ
	updateHeight(b);//b ���� ������Ʈ
	return b;
}
int updateHeight(node* w) {//���� ������Ʈ �Լ�
	int h = w->left->height + 1;
	if (h < w->right->height + 1) {//h�� �ڽ� ��� �� �ִ�+1���� ����
		h = w->right->height + 1;
	}
	if (h != w->height) {//���� ������ w�� ���̿� h�� ����
		w->height = h;
		return 1;//�� ��ȯ
	}
	return 0;//���� ��ȯ
}
int isBalanced(node* w) {//���� üũ �Լ�
	if (w->left->height > w->right->height) {//�� �ڽ� ������ �� ���밪�� 2���� ������ �� �ƴ� �� ���� ��ȯ
		return (w->left->height - w->right->height) < 2;
	}
	return (w->right->height - w->left->height) < 2;
}
void searchAndFixAfterInsertion(node* w) {//������ Ž�������� �Լ�
	w->left->height = 0;
	w->right->height = 0;
	w->height = 1;
	if (isRoot(w))//w�� ��Ʈ ����Ͻ� �Լ� ����
		return;
	node* z = w->parent;//z�� w�� �θ� ���
	node* y = NULL;
	node* x = NULL;

	while (updateHeight(z) && isBalanced(z)) {//��Ʈ�� ���� ó�� ������ �ұ��� ��带 z
		if (isRoot(z))
			return;
		z = z->parent;
	}

	if (isBalanced(z))
		return;
	if (z->left->height > z->right->height)//z�� ���� �ڽ��� y
		y = z->left;
	else
		y = z->right;
	if (y->left->height > y->right->height)//y�� ���� �ڽ��� x
		x = y->left;
	else
		x = y->right;

	restructure(&x, &y, &z);//�簳��
	return;
}
node* insertItem(node* root, int k) {//������ ���� �Լ�
	node* w = treeSearch(root, k);//���� Ž�� Ʈ��
	if (isInternal(w))
		return;
	else {
		w->key = k;//w��忡 key set
		expandExternal(w, root);//�ܺ� ��� Ȯ�� �Լ�
		searchAndFixAfterInsertion(w);
		while (!isRoot(w)) {//w�� �ٽ� root���� ����
			w = w->parent;
		}
		return w;//root��� ��ȯ
	}
}
int findElement(node* root, int k) {//���� Ž��
	node* w = treeSearch(root, k);
	if (isExternal(w))
		return-1;
	else
		return w->key;
}
void printAvlTree(node* w) {//avlƮ�� ��� �Լ�
	if (isInternal(w)) {
		printf(" %d", w->key);
		printAvlTree(w->left);
		printAvlTree(w->right);
	}
}
void freeTree(node* w) {//Ʈ�� ���� �Ҵ� �޸� ���� �Լ�
	if (w != NULL) {
		freeTree(w->left);
		freeTree(w->right);
		putnode(w);
	}
}
node* inOrderSucc(node* w) {//w�� ������ȸ node ��ȯ �Լ�
	w = w->right;//w�� �ڽ� ���
	if (isExternal(w)) {
		return NULL;
	}
	while (isInternal(w->left)) {
		w = w->left;
	}

	return w;
}
node* sibling(node* w) {//w�� ���� ��� ��ȯ �Լ�
	if (isRoot(w))
		return;
	if (w->parent->left == w)
		return w->parent->right;
	else
		return w->parent->left;
}
node* reduceExternal(node** root, node* z) {//�ܺγ���� ��� �Լ�
	node* w = z->parent;//w�� z�� �θ���� �ʱ�ȭ
	node* zs = sibling(z);//zs�� z�� ���� ���� �ʱ�ȭ
	if (isRoot(w)) {//w�� ��Ʈ ����� zs�� ��Ʈ ���� �ʱ�ȭ
		*root = zs;
		zs->parent = NULL;
	}
	else {
		node* g = w->parent;//�����θ� �ʱ�ȭ
		zs->parent = g;//zs�� �θ� �����θ�� ����
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	}
	putnode(z);//z ��� �����Ҵ� �޸� ����
	putnode(w);//w ��� �����Ҵ� �޸� ����
	return zs;//zs ��� ��ȯ
}
void searchAndFixAfterRemoval(node* z) {//������ Ž�� �� ���� �Լ�
	node* x;
	node* y;
	while (updateHeight(z) && isBalanced(z)) {//��Ʈ�� ���� ���� ó�� ������ �ұ��� ��� z
		if (isRoot(z))
			return;
		z = z->parent;
	}
	if (isBalanced(z))//������ ���� �ִٸ� �Լ� ����
		return;

	if (z->left->height > z->right->height)//z�� ���� �ڽ� y
		y = z->left;
	else
		y = z->right;

	if (y->left->height > y->right->height)//y�� ���� �ڽ� x
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;
	else {//���̰� ������ y�� ���� �� ����
		if (z->left == y)
			x = y->left;
		else
			x = y->right;
	}
	node* b = restructure(&x, &y, &z);//�簳�� �Լ� ����
	if (isRoot(b))//b�� ��Ʈ ����� �Լ� ����
		return;
	searchAndFixAfterRemoval(b->parent);//b�� �θ�κ��� ��Ʈ���� �����ϸ� ������ ���� ��带 ��������� ����
}
node* removeElement(node* root, int k) {//key���� �´� ��� ���� �Լ�
	node* w = treeSearch(root, k);//���� Ž��
	if (isExternal(w)) {//key�� �ش��ϴ� node�� ���� ��
		printf("X\n");//X���
		return root;//root ��ȯ
	}

	node* z = w->left;//z�� w�� ���� �ڽ����� �ʱ�ȭ
	node* zs;

	if (!isExternal(z)) {//z�� �ܺγ�尡 �ƴ϶�� z�� w�� ������ �ڽ����� ����
		z = w->right;
	}

	if (isExternal(z)) {//z�� �ܺ� ����Ͻ� z��� ���
		zs = reduceExternal(&root, z);
	}
	else {//���� ����� ��
		node* y = inOrderSucc(w);//y�� w�� ���� ������ȸ�ڷ� �ʱ�ȭ
		z = y->left;//z�� y�� ���� �ڽ����� �ʱ�ȭ
		w->key = y->key;//w node�� yŰ ������ ��
		zs = reduceExternal(root, z);//z ��� ���
	}
	if(!isRoot(zs))//zs ��尡 ��Ʈ�� �ƴ϶�� 
		searchAndFixAfterRemoval(zs->parent);
	printf("%d\n", k);//���ŵ� key�� ���
	while (!isRoot(zs)) {//zs�� �ٽ� ��Ʈ ���� ����
		zs = zs->parent;
	}
	return zs;//��Ʈ ��� ��ȯ
}
int main() {
	struct node* root = getnode();//��Ʈ ��� ���� �Ҵ�
	char cmd = -1;//��ɾ� �Է� -1�� �ʱ�ȭ
	while (cmd != 'q') {
		scanf("%c", &cmd);
		int key;
		if (cmd == 'i') {//i �Է½� Ű ���� �Լ� ����
			scanf("%d", &key);
			getchar();
			root = insertItem(root, key);
		}
		else if (cmd == 's') {//s �Է½� Ű Ž�� �Լ� ����
			scanf("%d", &key);
			getchar();
			int i = findElement(root, key);
			if (i == -1) {//�ش� Ű�� �������� ���� �� X���
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
		else if (cmd == 'p') {//p �Է½� tree ��� �Լ� ����
			getchar();
			printAvlTree(root);
			printf("\n");
		}
	}
	freeTree(root);//���� �Ҵ� �޸� ���� �Լ�
	return 0;
}