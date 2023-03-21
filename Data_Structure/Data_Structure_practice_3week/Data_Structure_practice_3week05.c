#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void recursive_Hanoi(int, char, char, char);
int main() {
	int N;
	scanf("%d", &N);
	recursive_Hanoi(N, 'A', 'B', 'C');

	return 0;
}

void recursive_Hanoi(int N, char a, char b, char c) {
	if (N == 1) {
		printf("%c %c\n", a, c);
		return 0;
	}
	recursive_Hanoi(N - 1, a, c, b);
	printf("%c %c\n", a, c);
	recursive_Hanoi(N - 1, b, a, c);
	return 0;

}