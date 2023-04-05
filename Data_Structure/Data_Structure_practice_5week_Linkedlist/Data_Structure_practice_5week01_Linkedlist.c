#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int size = 0;
typedef struct node {
	struct node* pre;
	struct node* next;

	char data;
}node;

void print(node* head)
{
	node* p = head->next;
	while (p->next != NULL) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}
void add(node* head, int r, char e) {
	node* p = head;
	if (r<1 || r>size + 1)
		printf("invalid position\n");
	else {
		for (int i = 1; i < r + 1; i++) {
			p = p->next;
		}
		node* q = (node*)malloc(sizeof(node));
		q->data = e;
		q->pre = p->pre;
		q->next = p;
		(p->pre)->next = q;
		p->pre = q;
		size++;
	}
}
void delete(node* head, int r)
{
	if (r<0 || r>size)
		printf("invalid position\n");
	else {
		node* p = head;
		for (int i = 1; i <= r; i++) {
			p = p->next;
		}
		p->next->pre = p->pre;
		p->pre->next = p->next;
		size--;
		free(p);
	}

}
char get(node* head, int r) {
	if (r<0 || r>size)
		return -1;
	else {
		node* p = head;
		for (int i = 1; i <= r; i++) {
			p = p->next;
		}
		return p->data;

	}
}
int main() {
	struct node* head = (node*)malloc(sizeof(node));
	struct node* tail = (node*)malloc(sizeof(node));
	head->next = tail;
	head->pre = NULL;
	tail->pre = head;
	tail->next = NULL;

	int n, r;
	char command, e;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &command);
		if (command == 'A') {
			scanf("%d %c", &r, &e);
			getchar();
			add(head, r, e);
		}
		else if (command == 'D') {
			scanf("%d", &r);
			getchar();
			delete(head, r);
		}
		else if (command == 'G') {
			scanf("%d", &r);
			getchar();
			if (get(head, r) == -1)
				printf("invalid position\n");
			else
				printf("%c\n", get(head, r));
		}
		else if (command == 'P') {
			getchar();
			print(head);
		}
	}

	return 0;
}