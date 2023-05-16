#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	struct node* next;
	struct node* prev;
	int data;

}node;
struct node* f = NULL;
struct node * r = NULL;
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void putnode(node* p) {
	free(p);
}
int Isempty() {
	return(f == NULL);
}
void addfront(int e) {
	node* p = getnode();
	p->data = e;
	if (Isempty()) {
		f = p;
		r = p;
	}
	else {
		f->prev = p;
		p->next = f;
		f = p;
		p->data = e;
	}

}
void addrear(int e) {
	node* p = getnode();
	p->data = e;
	if (Isempty()) {
		f = p;
		r = p;
	}
	else {
		r->next = p;
		p->prev = r;
		r = p;
		p->data = e;
	}

}
int deletefront() {
	int e;
	e=f->data;
	if (Isempty()) {
		printf("underflow\n");
		return -1;
	}
	else {
		node* p = f;	
		if (f->next != NULL) {
			f->next->prev = NULL;
			f = f->next;
			putnode(p);
		}
		else {
			f = NULL;
		}

	}
	return e;
}
int deleterear() {
	int e;
	if (Isempty()) {
		printf("underflow\n");
		return -1;
	}
	else {
		e = f->data;
		node* p = r;
		if (r->prev != NULL) {
			r->prev->next = NULL;
			r = r->prev;
			putnode(p);
		}
		else
			f = NULL;
	}
	return e;
}
void Print() {
	node* p = f;
	while (p != NULL) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
}
int main() {
	int n, e;
	char cmd[3];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (strcmp(cmd, "AF") == 0) {
			scanf("%d", &e);
			getchar();
			addfront(e);
		}
		else if (strcmp(cmd, "AR") == 0) {
			scanf("%d", &e);
			getchar();
			addrear(e);
		}
		else if (strcmp(cmd, "DF") == 0) {
			getchar();
			if (deletefront() == -1)
				break;
		}
		else if (strcmp(cmd, "DR")==0) {
			getchar();
			if (deleterear() == -1)
				break;
		}
		else if (strcmp(cmd, "P")==0) {
			getchar();
			Print();
		}
	}
	return 0;
}