#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int make_odd(int);
//int make_even(int);
//int make_sum(int);
//
//int main() {
//	int odd_sum, even_sum, all_sum;
//	int N;
//	scanf("%d", &N);
//
//	odd_sum = make_odd(N);
//	even_sum = make_even(N);
//	all_sum = make_sum(N);
//
//	printf("%d %d %d", odd_sum, even_sum, all_sum);
//
//	return 0;
//}
//
//int make_odd(int a) {
//	int i=1, sum=0;
//	while (i <= a)
//	{
//		sum += i;
//		i = i + 2;
//	}
//	return sum;
//
//}
//int make_even(int a) {
//	int i=2, sum = 0;
//	do
//	{
//		sum += i;
//		i += 2;
//	}while(i <= a);
//
//	return sum;
//}
//int make_sum(int a) {
//	int i = 0, sum=0;
//	for (i = 0; i <= a; i++) {
//		sum += i;
//	}
//	return sum;
//}
//int main() {
//	int a[10], cnt = 0, flag=0;
//	int i, j;
//
//	for (i = 0; i < 10; i++) {
//		scanf("%d", &a[i]);
//		a[i] = a[i] % 42;
//	}
//	
//	for (i = 0; i < 10; i++)
//	{
//		flag = 0;
//		for (j = i+1; j < 10; j++) {
//			if (a[i] == a[j])
//				flag = 1;
//		}
//		if (flag == 0)
//			cnt++;
//	}
//	printf("%d", cnt);
//
//	return 0;
//}
//int main() {
//	double score[1000];
//	double sum=0, max=0;
//	int N, i;
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%lf", &score[i]);
//		if (max < score[i])
//			max = score[i];
//	}
//	for (i = 0; i < N; i++) {
//		sum = sum + score[i] / max * 100;
//	}
//	sum = sum / N;
//	printf("%f", sum);
//	return 0;
//
//}
//
//int main() {
//	char a[81];
//	int  N, cnt=0, score=0, i, j, k, sum[100000];
//	scanf("%d", &N);
//	for (k = 0; k < N; k++) {
//		score = 0;
//		cnt = 0;
//		scanf("%s", a);
//		for (i = 0; i < strlen(a); i++) {
//			if (a[i] == 'O') {
//				cnt++;
//				score += cnt;
//			}
//			else
//				cnt = 0;
//		}
//		sum[k] = score;
//	}
//	for (i = 0; i < N; i++) {
//		printf("%d\n", sum[i]);
//	}
//	return 0;
//
//}
//int main() {
//	int C, N, i, score[1000], j, cnt = 0;
//	double average, result[1000];
//	scanf("%d", &C);
//	for (i = 0; i < C; i++) {
//		scanf("%d", &N);
//		average = 0.0;
//		cnt = 0;
//		for (j = 0; j < N; j++) {
//			scanf("%d", &score[j]);
//			average += score[j];
//		}
//		average = average / N;
//		for (j = 0; j < N; j++) {
//			if (score[j] > average)
//				cnt++;
//		}
//		result[i] = 100.0*cnt / N ;
//	}
//	for (i = 0; i < C; i++) {
//		printf("%.3f%%\n", result[i]);
//	}
//	return 0;
//}
//
//long long sum(int* a, int n) {
//	long long ans = 0;
//	for (int i = 0; i < n; ++i) {
//		ans += a[i];
//	}
//	return ans;
//}
//int main() {
//	int a[10001] = {0};
//	int i, j, self_number;
//	for (i = 1; i <= 10000; i++) {
//		self_number = i;
//		for (j = 0; j >= 0; j++) {
//			self_number = self_number + self_number / 10%10 + self_number / 100%10 + self_number / 1000 + self_number % 10;
//			if (self_number > 10000)
//				break;
//			a[self_number] = 1;
//		}
//	}
//	for (i = 1; i <= 10000; i++) {
//		if (a[i] == 0) {
//			printf("%d\n", i);
//		}
//	}
//}
//int main() {
//	int N;
//	int i, cnt=0;
//	int a, b, c;
//	scanf("%d", &N);
//	for (i = 1; i <= N; i++)
//	{
//		if (i < 100)
//			cnt++;
//		else if (i >= 100)
//		{
//			a = i / 100;
//			b = i / 10%10;
//			c = i % 10;
//			if (a - b == b - c)
//				cnt++;
//		}
//	}
//	printf("%d", cnt);
//
// return 0;
//}
//int main() {
//	int i,j, flag=0;
//	char arr[101];
//	scanf("%s", arr);
//	for (i = 'a'; i <= 'z'; i++) {
//		flag = -1;
//		for (j = 0; j < strlen(arr); j++) {
//			if (arr[j] == i) {
//				flag = j;
//				break;
//			}
//	
//		}
//		printf("%d ", flag);
//	}
//}
//int main() {
//	char c;
//	int N, R, i, j;
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%d ", &R);
//		while ((c = getchar()) != '\n')
//		{
//			for (j = 0; j < R; j++) {
//				printf("%c", c);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main() {
//	char arr[1000000];
//	int tmp, i, j, max=-1, flag=0;
//	char max_alpha;
//	scanf("%s", arr);
//	for (i = 0; i < strlen(arr); i++) {
//		if (arr[i] >= 97 && arr[i] <= 122) {
//			arr[i] = arr[i] - 32;
//		}
//	}
//	for (i = 0; i < strlen(arr); i++) {
//		tmp = 0;
//		for (j = i + 1; j < strlen(arr); j++)
//		{
//			if (arr[i] == arr[j])
//				tmp++;
//		}
//		if (tmp == max)
//			flag = 1;
//		if (tmp > max)
//		{
//			max = tmp;
//			max_alpha = arr[i];
//			flag = 0;
//		}
//	}
//	if (flag == 0)
//		printf("%c", max_alpha);
//	else
//		printf("?");
//	return 0;
//}天天天天天
//long loop_factorial(int n);
//long recursive_factorial(int n);
//int main() {
//	int num = 5;
//	printf("%d\n", recursive_factorial(num));
//	printf("%d\n", loop_factorial(num));
//
//	return 0;
//
//}
//long loop_factorial(int n) {
//	long result = 1;
//	for (int i = n; i > 0; i--) {
//		result *= i;
//	}
//	
//	return result;
//}
//long recursive_factorial(int n) {
//	if (n > 0) {
//
//		return n * recursive_factorial(n - 1);
//	}
//	else
//	return 1;
//
//}
//void print_binary(unsigned long n);
//void print_binary_loop(unsigned long n);
//
//int main() {
//	unsigned long num = 253;
//
//	print_binary_loop(num);
//	print_binary(num);
//
//	printf("\n");
//
//	return 0;
//}
//
//void print_binary(unsigned long n) {
//	if (n > 1) {
//		print_binary(n / 2);
//	}
//	printf("%d", n % 2);
//}
//
//void print_binary_loop(unsigned long n) {
//
//	int a[1000], i = 0;
//	while (1) {
//		int quotient = n / 2;
//		int remainder = n % 2;
//		a[i] = remainder;
//		i++;
//
//		n = quotient;
//		if (n == 0)
//			break;
//
//	}
//	for (i = i - 1; i >= 0; i-- )
//		printf("%d", a[i]);
//	printf("\n");
//
//}

int fibonacci(int n);
int main() {
	for (int count = 1; count < 13; count++) {
		printf("%d ", fibonacci(count));
	}

	return 0;
}

int fibonacci(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}