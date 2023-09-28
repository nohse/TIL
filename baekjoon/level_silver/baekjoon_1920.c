#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
void insertion_sort(long long arr[], int n) {//���� ����
	for (int pass = 1; pass <= n - 1; pass++) {
		long long save = arr[pass];
		int j = pass - 1;
		while ((j >= 0) && (arr[j] > save)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = save;
	}
}
void quickSort(long long arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot ���� (���) 
	long long temp;
	do
	{
		while (arr[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
			left++;
		while (arr[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
			right--;
		if (left <= right)    // left�� right���� ���ʿ� �ִٸ� ��ȯ 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			/*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
			left++;
			right--;
		}
	} while (left <= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 

	/* recursion */
	if (L < right)
		quickSort(arr, L, right);    // ���� �迭 ��������� �ݺ� 

	if (left < R)
		quickSort(arr, left, R);    // ������ �迭 ��������� �ݺ� 
}
int binary_search_tree(long long arr[], long long key, int size) {
	int front, rear, pivot;
	front = 0;
	rear = size - 1;

	while (1) {
		pivot = (front + rear) / 2;
		if (arr[pivot] == key) return 1;
		if (arr[front] == key) return 1;
		if (arr[rear] == key) return 1;

		if (arr[pivot] < key)
			front = pivot + 1;
		else
			rear = pivot - 1;

		if (front >= rear)
			return 0;
	}
}
int main() {
	int N;
	int M;
	long long A[100000];
	long long b;
	int flag = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %lld", &A[i]);
	}
	quickSort(A, 0,N-1);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld", &b);
		printf("%d\n", binary_search_tree(A, b, N));
	}

	return 0;
}