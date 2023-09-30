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
	int pivot = arr[(L + R) / 2];    // pivot ���� (���) 
	int temp;
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