#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>//rand,srand함수 사용을 위해 인클루드
#include<time.h>//time 함수 사용을 위해 인클루드
#include<windows.h>
int countOnesButSlow(int **, int n);//점근 표기법 O(n^2) 함수
int countOnes(int **, int n);//점근 표기법 O(n) 함수

int main(){
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;//각 함수들의 시간측정을 위한 코드
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);



	int i, j;
	int Slow_cnt1, Slow_cnt2,Slow_cnt3,cnt1,cnt2,cnt3;//각 n별 빠른 버전 느린 프로그램이 계산한 1의 총수를 저장하는 변수들
	int k[30000];//각 행별 1의 갯수들을 저장한 변수
	int kTotal1,kTotal2,kTotal3;//각 n별 ktotal을 저장한느 변수들
	double fsec1, fsec2, fsec3, ssec1, ssec2, ssec3;//빠른 버전, 느린 버전의 각 n별 실행시간을 저장하는 변수들


	int n = 10000;//n이 10000일때
	int** arr1 = (int**)malloc(n * sizeof(int*));//동적 할당
	for (int i = 0; i < n; i++) {
		arr1[i] = (int*)malloc(n * sizeof(int));
	}

	k[0] = rand() % (int)(n * 0.1+1) + (int)(n * 0.9);//첫 행의 초기 난수 대입
	kTotal1 = k[0];
	for (i = 1; i < n; i++) {//1~n-1행까지 k값 난수로 대입
		k[i] = rand() % (int)(k[i - 1] * 0.1+1) + (int)(0.9 * k[i - 1]);
		kTotal1 += k[i];
	}
	for (i = 0; i < n; i++) {//동적 할당된 arr 배열에 각 행들의 k값 만큼 1 대입
		for (j = 0; j < k[i]; j++) {
			arr1[i][j] = 1;
		}
	}
	QueryPerformanceCounter(&start);//실행 시간 측정을 위한 함수
	Slow_cnt1 = countOnesButSlow(arr1, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	ssec1 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;//계산 한 실행 시간을 변수에 대입

	QueryPerformanceCounter(&start);
	cnt1 = countOnes(arr1, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fsec1 = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;



	n = 20000;//n이 20000일때
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


	n = 30000;//n이 30000일때
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

	printf("%d %d %.12f\n", kTotal3,cnt3, fsec3);//결과 값 출력
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