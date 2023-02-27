# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int*, int*);
void print_array(int*, int);
void selection_sort(int*, int);

int main() {
	int arr[] = { 64,25,12,22,11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, n);
	print_array(arr, n);

	return 0;
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}
void print_array(int a[], int b) {

	int i;
	for (i = 0; i < b; i++) {
		printf("%d ", a[i]);
	}
}
void selection_sort(int a[], int num) {

	int min, i,j;
	for (i = 0; i < num; i++) {
		min = i;
		for (j = i; j < num; j++) {
			if (a[min] > a[j])
				min = j;
		}
		swap(&a[i], &a[min]);
	}
}