#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int size = 0;
typedef struct node {
	struct node* pre;
	struct node* next;

	char c;
}node;
void add(struct node*, int, char);
void delet(struct node*, int);
char get(struct node*, int);
void print(node*);
int main() {
	int N, r;
	char command, message;
	struct node* head = (node*)malloc(sizeof(node));
	struct node* tail = (node*)malloc(sizeof(node));
	head->pre = NULL;
	head->next = tail;
	tail->pre = head;
	tail->next = NULL;

	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%c", &command);
		if (command == 'A') {
			scanf("%d %c", &r, &message);
			getchar();
			add(head, r, message);
		}
		else if (command == 'D') {
			scanf("%d", &r);
			getchar();
			delet(head, r);
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
void add(node* head, int r, char m) {
	if (r<0 || r>size + 1) {
		printf("invalid position\n");
	}
	else {
		node* p = head;
		node* q = (node*)malloc(sizeof(node));
		q->c = m;
		for (int i = 1; i <= r; i++) {
			p = p->next;
		}
		q->next = p;
		q->pre = p->pre;
		p->pre->next = q;
		p->pre = q;
		size++;
	}

}
void delet(node* head, int r) {
	if (r<0 || r>size) {
		printf("invalid position\n");
	}
	else {
		node* p = head;
		for (int i = 1; i <= r; i++) {
			p = p->next;
		}
		p->next->pre = p->pre;
		p->pre->next = p->next;
		free(p);
		size--;
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
		return p->c;
	}
}
void print(node* head) {
	node* p = head;
	for (int i = 1; i <= size; i++) {
		p = p->next;
		printf("%c", p->c);
	}
	printf("\n");
}