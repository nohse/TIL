#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int size = 0;
typedef struct node {
	struct node* next;
	struct node* prev;
	char data;
}node;
void invalidposition() {
	printf("invalid position\n");
	return;
}
node* getnode() {
	node* p = (node*)malloc(sizeof(node));

	return p;
}
void printchar(node* p) {
	printf("%c", p->data);
	return;
}
int isnull(node* p) {
	return p == NULL;
}
void putnode(node *p) {
	free(p);

	return;
}
void add(node* head, int index, char data) {
	node* p = head;
	if (index < 1||index>size+1) {
		invalidposition();
		return;
	}

	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	node* q = getnode();
	q->data = data;
	q->prev = p->prev;
	q->next = p;
	p->prev->next = q;
	p->prev = q;
	size++;
	return;
}
void delete(node* head, int index) {
	node* p = head;
	if (index<1 || index>size) {
		invalidposition();
		return;
	}
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	p->next->prev = p->prev;
	p->prev->next = p->next;

	size--;
}
void get(node* head, int index) {
	node* p = head;
	if (index<1 || index>size) {
		invalidposition();
		return;
	}
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	printchar(p);
	printf("\n");
	return;
}
void print(node* head, node* tail) {
	node* p = head->next;
	while (p != tail) {
		printchar(p);
		p = p->next;
	}
	printf("\n");
	return;

}
int main() {
	int a, index;
	char com, data;
	struct node* head = (node*)malloc(sizeof(node));
	struct node* tail = (node*)malloc(sizeof(node));
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;

	scanf("%d", &a);
	getchar();
	for (int i = 0; i < a; i++) {
		scanf("%c", &com);
		if (com == 'A') {
			scanf("%d %c", &index, &data);
			getchar();
			add(head, index, data);
		}
		else if (com == 'D') {
			scanf("%d", &index);
			getchar();
			delete(head, index);
		}
		else if (com == 'G') {
			scanf("%d", &index);
			getchar();
			get(head, index);
		}
		else if (com == 'P') {
			getchar();
			print(head,tail);
		}
	}
}