#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <Windows.h>
void reverse_Insertion_Sort(int arr[], int n) {//배열을 역순으로 정렬
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertion_sort(int arr[], int n) {//삽입 정렬
    for (int pass = 1; pass <= n - 1; pass++) {
        int save = arr[pass];
        int j = pass - 1;
        while ((j >= 0) && (arr[j] > save)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = save;
    }
}
void selection_sort(int arr[], int n) {//선택정렬
    for (int pass = 0; pass <= n - 2; pass++) {
        int minLoc = pass;
        for (int j = pass + 1; j <= n - 1; j++) {
            if (arr[j] < arr[minLoc])
                minLoc = j;
        }
        int tmp = arr[pass];
        arr[pass] = arr[minLoc];
        arr[minLoc] = tmp;
    }
}
int main() {

    int n, a;

    srand(time(NULL));
    LARGE_INTEGER ticksPerSec;//시간 측정을 위한 함수
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec);
    double elapsedTimeA;
    double elapsedTimeB;
    //기본
    printf("A의 n값 : ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * n);
    int* B = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a = rand() % 10001;
        *(A + i) = a;
        *(B + i) = a;
    }
    printf("A기본\n");
    QueryPerformanceCounter(&start);
    selection_sort(A, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    double elapsedTimeA = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("선택정렬 : %.2lf ms\n", elapsedTimeA);

    QueryPerformanceCounter(&start);
    insertion_sort(B, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    double elapsedTimeB = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("삽입정렬 : %.2lf ms\n", elapsedTimeB);

    //B 실험

    printf("B의 n값 : ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * n);
    int* B = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a = rand() % 10001;
        *(A + i) = a;
        *(B + i) = a;
    }
    printf("fin");

    printf("이미 정렬된 데이터B\n");
    insertion_sort(A, n);//실험 전 정렬
    insertion_sort(B, n);

    QueryPerformanceCounter(&start);
    selection_sort(A, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
     elapsedTimeA = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 100000.0;
    printf("선택정렬 : %.2lf ms\n", elapsedTimeA);

    QueryPerformanceCounter(&start);
    insertion_sort(B, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    elapsedTimeB = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 100000.0;
    printf("삽입정렬 : %.2lf ms\n", elapsedTimeB);


    //C 실험

    printf("C의 n값 : ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * n);
    int* B = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a = rand() % 10001;
        *(A + i) = a;
        *(B + i) = a;
    }
    printf("역순정렬 C\n");
    reverse_Insertion_Sort(A, n);//실험 전 역 정렬
    reverse_Insertion_Sort(B, n);

    QueryPerformanceCounter(&start);
    selection_sort(A, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    elapsedTimeA = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("선택정렬 : %.2lf ms\n", elapsedTimeA);

    QueryPerformanceCounter(&start);
    insertion_sort(B, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    elapsedTimeB = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("삽입정렬 : %.2lf ms\n", elapsedTimeB);

    return 0;
}