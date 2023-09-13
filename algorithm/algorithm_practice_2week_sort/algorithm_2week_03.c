#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <Windows.h>
void reverse_Insertion_Sort(int arr[], int n) {
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
void insertion_sort(int list[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
        }

        list[j + 1] = key;
    }
}
void selection_sort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main() {
    srand(time(NULL));
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec);

    int n, a;
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * n);
    int* B = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a = rand() % 10001;
        *(A + i) = a;
        *(B + i) = a;
    }
    printf("A\n");
    QueryPerformanceCounter(&start);
    selection_sort(A, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    double elapsedTimeA = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("%.2lf ms\n", elapsedTimeA);

    QueryPerformanceCounter(&start);
    insertion_sort(B, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    double elapsedTimeB = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("%.2lf ms\n", elapsedTimeB);





    for (int i = 0; i < n; i++) {
        a = rand() % 10001;
        *(A + i) = a;
        *(B + i) = a;
    }

    printf("B\n");
    insertion_sort(A, n);
    insertion_sort(B, n);

    QueryPerformanceCounter(&start);
    selection_sort(A, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
     elapsedTimeA = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("%.2lf ms\n", elapsedTimeA);

    QueryPerformanceCounter(&start);
    insertion_sort(B, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    elapsedTimeB = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("%.2lf ms\n", elapsedTimeB);




    for (int i = 0; i < n; i++) {
        a = rand() % 10001;
        *(A + i) = a;
        *(B + i) = a;
    }
    printf("C\n");
    reverse_Insertion_Sort(A, n);
    reverse_Insertion_Sort(B, n);

    QueryPerformanceCounter(&start);
    selection_sort(A, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    elapsedTimeA = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("%.2lf ms\n", elapsedTimeA);

    QueryPerformanceCounter(&start);
    insertion_sort(B, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    elapsedTimeB = (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000.0;
    printf("%.2lf ms\n", elapsedTimeB);

    return 0;
}
//이미 정렬 된 경우 삽입 정렬이 빠르다
