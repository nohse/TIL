#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct node {
	int number;
	struct node* next;
}node;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->number = 0;
	return p;
}
void insertItem(node A[], int key, int M) {
	int i;
	i = key % M;
	node* newNode = getnode();
	newNode->number = key;
	newNode->next = A[i].next;
	A[i].next = newNode;
}
void printItem(node A[], int M) {
	int i = 0;
	for (i = 0; i < M; i++) {
		node* cursor = A[i].next;
		while (cursor != NULL) {
			printf(" %d", cursor->number);
			cursor = cursor->next;
		}
	}
	printf("\n");
}
int searchItem(node A[], int key, int M) {
	int i;
	i = key % M;
	int num = 1;
	int flag = 0;
	node* cursor = A[i].next;
	while (cursor != NULL) {
		if (cursor->number == key) {
			flag++;
			break;
		}
		cursor = cursor->next;
		num++;
	}
	if (flag == 1) {
		printf("%d\n", num);
		return num;
	}
	else
		printf("0\n");
	return 0;
}
void deleteItem(node A[], int key, int M) {
	int i;
	i = key % M;
	int num = searchItem(A, key, M);
	if (num == 0)
		return;
	node* cursor = &A[i];
	for (int i = 0; i < num-1; i++) {
		cursor=cursor->next;
	}
	node* p = cursor->next;
	cursor->next = cursor->next->next;
	free(p);

}
int main() {
	int M;
	char select=-1;
	scanf("%d", &M);
	getchar();
	struct node* A = (node*)malloc(sizeof(node) * M);
	for (int i = 0; i < M; i++) {

		(A + i)->number = NULL;

		(A+ i)->next = NULL;

	}
	while (select != 'e') {
		scanf("%c", &select);
		int key;
		if (select == 'i') {
			scanf("%d", &key);
			getchar();
			insertItem(A, key, M);
		}
		else if (select == 's') {
			scanf("%d", &key);
			getchar();
			searchItem(A, key,M);
		}
		else if (select == 'd') {
			scanf("%d", &key);
			getchar();
			deleteItem(A, key,M);
		}
		else if (select == 'p') {
			getchar();
			printItem(A,M);
		}
		else if (select == 'q') {
			break;
		}
	}
	return 0;
}