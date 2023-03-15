#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int*, int*);

int main() {
	int arr[50];
	int num;
	int a, b;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d %d", &a, &b);
	swap(&arr[a], &arr[b]);

	for(int i=0;i<num;i++)
		printf(" %d", arr[i]);
	return 0;
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}