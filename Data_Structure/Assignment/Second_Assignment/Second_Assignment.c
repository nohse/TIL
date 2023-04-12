#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	struct node* nextelement;
	struct node* nextgroup;

}node;
typedef struct _Item {
	node* header;
	char name;
} Item;
node* getnode() {
	node* n = (node*)malloc(sizeof(node));
	n->nextelement = NULL;
	n->nextgroup = NULL;
	return n;
}
void putnode(node* p) {
	free(p);
}
void initshare(Item E[], Item G[], int NE, int NG, char* nameE, char* nameG) {


	for (int i = 0; i < NE; i++) {
		node* p = getnode();
		p->nextgroup = p;
		E[i].header = p;
		E[i].name = nameE[i];
	}
	for (int i = 0; i < NG; i++) {
		node* p = getnode();
		p->nextelement = p;
		G[i].header = p;
		G[i].name = nameG[i];
	}
}
int getindex(Item a[], int N, char name);
void addshare(Item E[], Item G[], char e, char g);
void traverseshareelements(Item E[], Item G[], char g);
void traversesharegroup(Item E[], Item G[], char e);
char getename(Item* E, int NE, node* p) {
	node* q = p->nextgroup;
	while (q->nextelement != NULL) {
		q = q->nextgroup;
	}
	for (int i = 0; i < NE; i++) {
		if (E[i].header == q) {
			return E[i].name;
		}
	}

	return 0;
}
void removenode(node* target) {
	node* p;

	node* nextE = target->nextelement;
	p = nextE;
	while (p->nextelement != target)
		p = p->nextelement;
	p->nextelement = nextE;

	node* nextG = target->nextgroup;
	p = nextG;
	while (p->nextgroup != target)
		p = p->nextgroup;
	p->nextgroup = nextG;

	putnode(target);
	printf("OK\n");
}
void removeshare(Item E[], Item G[], char e, char g) {
	int numg = getindex(G, 5, g);
	int nume = getindex(E, 4, e);
	node* HG = G[numg].header;
	node* HE = E[nume].header;
	node* p = HG->nextelement->nextelement;
	node* q = HE->nextgroup;
	while (1) {
		q = q->nextgroup;
		while (1) {
			if (p == q) {
				removenode(p);
				break;
			}
			else if (p == HG->nextelement) {
				p = p->nextelement;
				break;
			}
			p = p->nextelement;
		}
		if (p == q)
			break;
		if (q == HE->nextgroup) {
			printf("0\n");
			break;
		}
	}
	//for (int i = 0; i < nume ; i++) {
	//	p = p->nextelement;
	//}
	//for (int i = 0; i < nume; i++) {
	//	p = p->nextgroup;
	//}

}
char getgname(Item* G, int NG, node* p) {
	node* q = p->nextelement;
	while (q->nextgroup != NULL)
		q = q->nextelement;

	for (int i = 0; i < NG; i++) {
		if (G[i].header == q)
			return G[i].name;
	}

	return 0;
}
int main() {
	Item E[5], G[4];
	int NE = 4, NG = 5;
	char nameE[] = { '1','2','3','4' };
	char nameG[] = { 'A','B','C','D','E'};
	initshare(E, G, NE,NG,nameE,nameG);
	char cmd, g, e;
	while (1) {
		scanf("%c", &cmd);
		getchar();
		if (cmd == 'a') {
			scanf("%c %c", &e, &g);
			getchar();
			addshare(E, G, e, g);
		}
		else if (cmd == 'r') {
			scanf("%c %c", &e, &g);
			getchar();
			removeshare(E, G, e, g);
		}
		else if (cmd == 'e') {
			scanf("%c", &g);
			getchar();
			traverseshareelements(E, G, g);
		}
		else if (cmd == 'g') {
			scanf("%c", &e);
			getchar();
			traversesharegroup(E, G, e);
		}
		else if (cmd == 'q')
			exit(0);
	}
	for (int i = 0; i < NE; i++) {
		node* p = E[i].header;
		while (p != NULL) {
			node* q = p;
			p = p->nextgroup;
			free(q);
		}
	}
	for (int i = 0; i < NG; i++) {
		node* p = G[i].header;
		while (p != NULL) {
			node* q = p;
			p = p->nextelement;
			free(q);
		}
	}
	return 0;

}
void traversesharegroup(Item E[], Item G[], char e) {
	int nume = getindex(E, 4, e);
	node* HE = E[nume].header;

	node* p = HE->nextgroup;
	if (p == HE)
		printf("0\n");
	else {
		while (p != HE) {
			char group = getgname(G, 5, p);
			printf("%c ", group);
			p = p->nextgroup;
		}
		printf("\n");
	}
}
void traverseshareelements(Item E[], Item G[], char g) {
	int numg = getindex(G, 5, g);
	node* HG = G[numg].header;
	node* p = HG->nextelement;
	if (p == HG)
		printf("0\n");
	else {
		while (p != HG) {
			char elem = getename(E, 4, p);
			printf("%c ", elem);
			p = p->nextelement;
		}
		printf("\n");
	}
}
void addshare(Item E[], Item G[], char e, char g) {
	node* p = getnode();
	int numg = getindex(G, 5, g);
	int numi = getindex(E, 4, e);
	node* HG = G[numg].header;
	node* HE = E[numi].header;
	p->nextelement = HG->nextelement;
	p->nextgroup = HE->nextgroup;
	HG->nextelement = p;
	HE->nextgroup = p;
	printf("OK\n");
}
int getindex(Item a[], int N, char name) {
	for (int i = 0; i < N; i++) {
		if (a[i].name == name)
			return i;
	}
	return -1;
}