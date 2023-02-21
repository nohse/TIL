#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibonacci(int n);
int main() {
	for (int count = 1; count < 13; count++) {
		printf("%d ", fibonacci(count));
	}

	return 0;
}
//계산들이 중복되어 비효율적으로 구현된다, 메모리를 많이 차지한다 -> 배열에 저장해서 활용할 수 있다 
int fibonacci(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}