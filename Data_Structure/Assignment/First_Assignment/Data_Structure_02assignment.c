#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>//rand,srand�Լ� ����� ���� ��Ŭ���
#include<time.h>//time �Լ� ����� ���� ��Ŭ���
#include<windows.h>
int countOnesButSlow(int **, int n);//���� ǥ��� O(n^2) �Լ�
int countOnes(int **, int n);//���� ǥ��� O(n) �Լ�

int main(){
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;//�� �Լ����� �ð������� ���� �ڵ�
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);



	int i, j;
	int Slow_cnt1, Slow_cnt2,Slow_cnt3,cnt1,cnt2,cnt3;//�� n�� ���� ���� ���� ���α׷��� ����� 1�� �Ѽ��� �����ϴ� ������
	int k[30000];//�� �ະ 1�� �������� ������ ����
	int kTotal1,kTotal2,kTotal3;//�� n�� ktotal�� �����Ѵ� ������
	double fsec1, fsec2, fsec3, ssec1, ssec2, ssec3;//���� ����, ���� ������ �� n�� ����ð��� �����ϴ� ������


	int n = 10000;//n�� 10000�϶�
	int** arr1 = (int**)malloc(n * sizeof(int*));//���� �Ҵ�
	for (int i = 0; i < n; i++) {
		arr1[i] = (int*)malloc(n * sizeof(int));
	}

	k[0] = rand() % (int)(n * 0.1+1) + (int)(n * 0.9);//ù ���� �ʱ� ���� ����
	kTotal1 = k[0];
	for (i = 1; i < n; i++) {//1~n-1����� k�� ������ ����
		k[i] = rand() % (int)(k[i - 1] * 0.1+1) + (int)(0.9 * k[i - 1]);
		kTotal1 += k[i];
	}
	for (i = 0; i < n; i++) {//���� �Ҵ�� arr �迭�� �� ����� k�� ��ŭ 1 ����
		for (j = 0; j < k[i]; j++) {
			arr1[i][j] = 1;
		}
	}
	QueryPerformanceCounter(&start);//���� �ð� ������ ���� �Լ�
	Slow_cnt1 = countOnesButSlow(arr1, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	ssec1 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;//��� �� ���� �ð��� ������ ����

	QueryPerformanceCounter(&start);
	cnt1 = countOnes(arr1, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fsec1 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;



	n = 20000;//n�� 20000�϶�
	int** arr2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr2[i] = (int*)malloc(n * sizeof(int));
	}

	k[0] = rand() % (int)(n * 0.1 + 1) + (int)(n * 0.9);
	kTotal2 = k[0];
	for (i = 1; i < n; i++) {
		k[i] = rand() % (int)(k[i - 1] * 0.1 + 1) + (int)(0.9 * k[i - 1]);
		kTotal2 += k[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < k[i]; j++) {
			arr2[i][j] = 1;
		}
	}
	QueryPerformanceCounter(&start);
	Slow_cnt2 = countOnesButSlow(arr2, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	ssec2 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;

	QueryPerformanceCounter(&start);
	cnt2 = countOnes(arr2, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fsec2 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;


	n = 30000;//n�� 30000�϶�
	int** arr3 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr3[i] = (int*)malloc(n * sizeof(int));
	}

	k[0] = rand() % (int)(n * 0.1 + 1) + (int)(n * 0.9);
	kTotal3 = k[0];
	for (i = 1; i < n; i++) {
		k[i] = rand() % (int)(k[i - 1] * 0.1 + 1) + (int)(0.9 * k[i - 1]);
		kTotal3 += k[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < k[i]; j++) {
			arr3[i][j] = 1;
		}
	}

	QueryPerformanceCounter(&start);
	Slow_cnt3 = countOnesButSlow(arr3, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	ssec3 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;

	QueryPerformanceCounter(&start);
	cnt3 = countOnes(arr3, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fsec3 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;

	printf("%d %d %.12f\n", kTotal3,cnt3, fsec3);//��� �� ���
	printf("%d %d %.12f\n", kTotal1, cnt1, fsec1);
	printf("%d %d %.12f\n", kTotal2, cnt2, fsec2);
	printf("%d %d %.12f\n", kTotal3, Slow_cnt3, ssec3);
	printf("%d %d %.12f\n", kTotal1, Slow_cnt1, ssec1);
	printf("%d %d %.12f\n", kTotal2, Slow_cnt2, ssec2);


	return 0;
}
int countOnesButSlow(int **A, int n)
{
	int cnt = 0;
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

int countOnes(int **A, int n)
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