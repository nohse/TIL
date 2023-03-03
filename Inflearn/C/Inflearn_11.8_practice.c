# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void swap(char**, char**);
void printStringArray(char* [], int size);
void selectionSort(char* [], int n);

int main() {

	char* arr[] = { "Cherry","AppleBee","Pineapple","Apple","Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);
	printStringArray(arr, n);
	selectionSort(arr, n);
	printStringArray(arr, n);

	return 0;
}
void swap(char** a, char** b)
{
	char* tmp = *a;
	*a = *b;
	*b = tmp;


}
void printStringArray(char* a[], int n) {
	int i = 0;
	for (i = 0; i < n; i++)
		puts(a[i]);
}
void selectionSort(char* arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(arr[j], arr[min_idx]) < 0)
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
	}
}