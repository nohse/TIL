#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int t = -1;
void push(char S[], char e) {
	t = t + 1;
	S[t] = e;
}
char pop(char S[]) {
	char tmp;
	tmp = S[t];
	t = t - 1;
	S[t+1] = 0;

	return tmp;
}
int isOperand(char a) {
	if (a >= 'A' && a <= 'Z')
		return 1;
	else return 0;
}
int numa(char a[], int i) {
	int s;
	if (a[i] == '(') {
		s = 0;
	}
	else if (a[i] == '|') {
		s = 1;
	}
	else if (a[i] == '&') {
		s = 2;
	}
	else if (a[i] == '>' || a[i] == '<') {
		s = 3;
	}
	else if (a[i] == '+' || a[i] == '-') {
		if (isOperand(a[i - 1]) == 1||a[i-1]==')')
			s = 4;
		else 
			s = 6;
	}
	else if (a[i] == '*' || a[i] == '/') {
		s = 5;
	}
	else if (a[i] == '!') {
		s = 6;
	}
	return s;
}
int nums(char a[], int i) {
	int s;
	if (a[i] == '(') {
		s = 0;
	}
	else if (a[i] == '|') {
		s = 1;
	}
	else if (a[i] == '&') {
		s = 2;
	}
	else if (a[i] == '>' || a[i] == '<') {
		s = 3;
	}
	else if (a[i] == '+' || a[i] == '-') {
		s = 4;
	}
	else if (a[i] == '*' || a[i] == '/') {
		s = 5;
	}
	else if (a[i] == '!'||a[i]=='@'||a[i]=='#') {
		s = 6;
	}
	return s;
}
int IsEmpty() {
	if (t == -1)
		return 1;
	else
		return 0;
}

int convert(char a[]) {
	int i = 0;
	int s, st;
	char S[10000], tmp;
	int N = strlen(a);
	for (i = 0; i < N; i++) {
		if (a[i] == '&' || a[i] == '|')
		{
			for (int j = i; j < N - 1; j++) {
				a[j + 1] = a[j + 2];
			}
			N--;
		}
		if (isOperand(a[i]))
			printf("%c", a[i]);
		else if (a[i] == '(') {
			push(S, a[i]);
		}
		else if (a[i] == ')') {
			while (S[t] != '(') {
				tmp = pop(S);
				if (tmp == '&' || tmp == '|') {
					printf("%c", tmp);
					printf("%c", tmp);
				}
				else if (tmp == '@')
					printf("+");
				else if (tmp == '#')
					printf("-");
				else
					printf("%c", tmp);
			}
			pop(S);
		}
		else {
			while (IsEmpty() == 0 && numa(a, i) <= nums(S, t)) {
				tmp = pop(S);
				if (tmp == '&' || tmp == '|') {
					printf("%c", tmp);
					printf("%c", tmp);
				}
				else if (tmp == '@')
					printf("+");
				else if (tmp == '#')
					printf("-");
				else
					printf("%c", tmp);
			}	
			if (numa(a, i) == 6) {
				if (a[i] == '+') {
					push(S, '@');
				}
				else if (a[i] == '-') {
					push(S, '#');
				}
				else
					push(S, a[i]);
			}
			else
				push(S, a[i]);

		}
	}
	while (IsEmpty() == 0) {
		tmp = pop(S);
		if (tmp == '&' || tmp == '|') {
			printf("%c", tmp);
			printf("%c", tmp);
		}
		else if (tmp == '@')
			printf("+");
		else if (tmp == '#')
			printf("-");
		else
			printf("%c", tmp);
	}
	printf("\n");
	return 0;
}
int main() {
	int N;
	char a[10000];
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", a);
		getchar();
		convert(a);
	}
}


