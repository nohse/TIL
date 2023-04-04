#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void add(char*, int, char);
void delete(char*, int);
char get(char*, int);
void print(char*);
int main() {
	char arr[100000] = { NULL };
	char w, tmp;
	int i, n, r;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &w);
		getchar();
		if (w == 'P') {
			print(arr);
			continue;
		}
		else if (w == 'A') {
			scanf("%d %c", &r, &tmp);
			getchar();
			add(arr, r, tmp);
		}
		else if (w == 'D') {
			scanf("%d", &r);
			getchar();
			delete(arr, r);
		}
		else if (w == 'G')
		{
			scanf("%d", &r);
			getchar();
			if (get(arr, r) == -1||r<=0)
				printf("invalid position\n");
			else
				printf("%c", get(arr, r));
		}
	}

	return 0;

}
void add(char* p, int a, char c) {
	int i=1;
	char tmp;
	if (a <= 0) {
		printf("invalid position\n");
	}
	else if (p[a] == NULL) {
		if (a != 1 && p[1] == NULL)
			printf("invalid position\n");
		else
			p[a] = c;
	}
	else
	{
		while (1)
		{
			if (p[i] == NULL)
				break;
			i++;
		}
		while (1) {
			p[i]=p[i-1];
			if (i == a)
				break;
			i--;
		}
		p[a] = c;
	}
}
void delete(char* p, int a) {
	int i = a;
	if (p[i] == NULL||a<=0)
		printf("invalid position\n");
	else {
		while (1) {
			if (p[i + 1] == NULL) {
				p[i] = NULL;
				break;
			}
			else
			{
				p[i] = p[i + 1];
			}
			i++;
		}
	}
}
char get(char* p, int r) {
	if (p[r] != NULL)
		return p[r];
	else
		return -1;
}
void print(char* p) {
	int i=1;
	while (1) {
		if (p[i] == NULL)
			break;
		else
			printf("%c", p[i]);
		i++;
	}
	printf("\n");
}