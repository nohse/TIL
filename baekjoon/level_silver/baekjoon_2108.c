#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int mean(int arr[], int N) {
	double result = 0;
	for (int i = 0; i < N; i++) {
		result += arr[i];
	}
	if (result > 0)
		result = (result / N) + 0.5;
	else {
		result = (result / N) - 0.5;
	}

	return (int)result;
}
void quickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;
	do
	{
		while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

	/* recursion */
	if (L < right)
		quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}
int mid(int arr[], int N) {
	return arr[N / 2];
}
int man(int arr[], int N) {
	int man[8001] = {0};
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		man[arr[i] + 4000]++;
	}
	int max = -1;
	for (int i = 0; i < 8001; i++) {
		if (man[i] > max) {
			max = man[i];
			cnt = 1;
		}
		else if (man[i] == max)
			cnt++;
	}
	for (int i = 0; i < 8001; i++) {
		if (man[i] == max && cnt > 1) {
			cnt = 1;
		}
		else if (man[i] == max && cnt == 1) {
			return i - 4000;
		}
	}
}
int range(int arr[], int N) {
	int min = 5000, max = -5000;
	for (int i = 0; i < N; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	return max - min;
}
int main() {
	int N;
	int arr[500001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0,N-1);
	int meanvalue = mean(arr, N);
	int midvalue = mid(arr, N);
	int manvalue = man(arr, N);
	int rangevalue = range(arr, N);
	printf("%d\n", meanvalue);
	printf("%d\n", midvalue);
	printf("%d\n", manvalue);
	printf("%d\n", rangevalue);

	return 0;
}