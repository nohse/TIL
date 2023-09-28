#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node* next;
	int data;
}node;
node* getnode() {
	struct node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->data = 0;
	return p;
}
void putnode(node*p) {
	free(p);
}
void pop(node* head) {
	int tmp = head->next->data;
	struct node* p = head->next;
	head->next = p->next;
	putnode(p);
}
void push(node* head, int n) {
	node* p = getnode();
	p->data = n;
	p->next = head->next;
	head->next = p;

}
int get(node* head) {
	if (isEmpty(head))
		return 0;
	return head->next->data;
}
int isEmpty(node* head) {
	return (head->next) == NULL;
}
int main() {
	int n;
	int a;
	int charindex = 0;
	int cnt = 1;
	char arr[300000] = {0};
	struct node* head = getnode();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		while (get(head) != a&&cnt<=n) {
			push(head, cnt);
			arr[charindex] = '+';
			charindex++;
			cnt++;
		}
		if (get(head) == a) {
			pop(head);
			arr[charindex] = '-';
			charindex++;
		}
		else
			printf("no\n");
		return;
	}
		for (int i = 0; i < 2 * n; i++) {
			printf("%c\n", arr[i]);
		}
	return 0;
}