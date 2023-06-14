#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt = 1;
typedef struct node {
	struct node *yes;
	struct node *no;
	char data[10000];
}node;
node* getnode() {
	struct node *p = (node*)malloc(sizeof(node));
	return p;
}
void putnode(node* p) {
	free(p);
}
int isInternal(node* v) {
	return(v->yes != NULL);
}
node* makeExternalNode() {
	struct node* v = getnode();
	printf("Enter decision: ");
	scanf(" %[^\n]%*c", v->data);
	v->no = NULL;
	v->yes = NULL;
	return v;
}
node* makeInternalNode() {
	struct	node* v = getnode();
	printf("Enter question: ");
	scanf(" %[^\n]%*c", v->data);
	printf("Question if yes to '%s'? ", v->data);
	char answer[5];
	scanf("%s", answer);
	if (strcmp(answer, "yes")==0) {
		if (cnt >= 5) {
			printf("error more than 5 questions\n");
			v->yes = makeExternalNode();
		}
		else {
			cnt++;
			v->yes = makeInternalNode();
		}
	}
	else {
		if (cnt < 3) {
			printf("less than 3 questions\n");
			cnt++;
			v->yes = makeInternalNode();
		}
		else {
			v->yes = makeExternalNode();
		}
	}
	printf("Question if no to '%s'? ", v->data);
	scanf("%s", answer);
	if (strcmp(answer,"yes")==0) {
		v->no = makeInternalNode();
	}
	else {
		v->no = makeExternalNode();
	}

	return v;

}
node* buildDecisionTree() {
	printf("***Let's build a dichotomous QA system\n");
	return makeInternalNode();
}
void processNode(node* v) {
	printf("%s ", v->data);
	if (isInternal(v)) {
		char answer[1000];
		scanf("%s", answer);
		if (strcmp(answer, "yes")==0) {
			processNode(v->yes);
		}
		else
			processNode(v->no);
	}
	printf("\n");
}
void runDecisionTree(node* v) {
	printf("***Please answer questions\n");
	processNode(v);
}
int main() {
	struct node* v;
	v = buildDecisionTree();
	printf("Tree complete. Now Running!!\n");
	for (int i = 0; i < 3; i++) {
			runDecisionTree(v);
		}

		return 0;
}