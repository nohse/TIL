#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void add(char*, int, char);
void delete(char*, int);
char get(char*, int);
void print(char*);


int main() {
	char V[10000] = {NULL};
	int n, index;
	char command, message;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &command);
		if (command == 'A')
		{
			scanf("%d %c", &index, &message);
			getchar();
			add(V, index-1, message);
		}
		else if (command == 'D')
		{
			scanf("%d", &index);
			getchar();
			delete(V, index-1);
		}
		else if (command == 'G')
		{
			scanf("%d", &index);
			getchar();
			if (get(V, index) == -1) {
				printf("invalid position\n");
			}
			else{
				printf("%c\n", get(V, index - 1));
			}
		}
		else if (command == 'P')
		{
			print(V);
			getchar();
		}
	}
}
void print(char* p) {
	for (int i = 0; i < strlen(p); i++) {
		printf("%c", p[i]);
	}
	printf("\n");
}
void add(char* p, int r, char e) {
	if (r < 0||strlen(p)+1<r) {
		printf("invalid position\n");
	}
	else {
		for (int i = strlen(p); i >= r; i--) {
			p[i + 1] = p[i];
		}
		p[r] = e;
	}
}
void delete(char* p, int r) {
	int tmp = strlen(p) - 1;
	if (r<0 || tmp<r) {
		printf("invalid position\n");
	}
	else {
		for (int i = r; i < strlen(p); i++) {
			p[i] = p[i + 1];
		}
	}
}
char get(char* p, int r) {
	if (r<0 || r>strlen(p)) {
		return -1;
	}
	else {
		return p[r];
	}

}