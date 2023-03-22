#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int countOnesButSlow(int A[][100], int n);//���� ǥ��� O(n^2) �Լ�
int countOnes(int A[][100], int n);//���� ǥ��� O(n) �Լ�
int main()
{

	int n;
	int arr[100][100];
	int i,j;
	int Slow_cnt, cnt;
	scanf("%d", &n);//�迭�� ũ�� �Է�
	for (i = 0; i < n; i++) {//�迭 �Է�
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	Slow_cnt = countOnesButSlow(arr, n);
	cnt = countOnes(arr, n);


	printf("%d\n", Slow_cnt);
	printf("%d\n", cnt);

	return 0;
}
int countOnesButSlow(int A[100][100], int n)
{
	int cnt=0;
	int i, j;
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < n && A[i][j] == 1) {
			cnt = cnt + 1;
			j = j + 1;
		}
	}
	return cnt;
}

int countOnes(int A[100][100], int n)
{
	int i = 0, j = n - 1, cnt = 0;
	while (j >= 0) {
		if (A[i][j] == 1) {
			cnt += j + 1;
			i++;
		}
		else {
			j--;
		}
	}
	return cnt;
}