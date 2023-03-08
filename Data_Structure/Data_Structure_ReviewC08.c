#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct student_info {
	char name[8];
	int korea;
	int eng;
	int math;
	float avg;
};
int main() {
	int N;
	struct student_info * arr;
	scanf("%d", &N);
	arr = (struct student_info*)malloc(sizeof(struct student_info) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", &arr[i].name, &arr[i].korea, &arr[i].eng, &arr[i].math);
		arr[i].avg = 0.0;
		arr[i].avg = (arr[i].korea + arr[i].eng + arr[i].math) / 3.0;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f", arr[i].name, arr[i].avg);
		if (arr[i].korea >= 90 || arr[i].eng >= 90 || arr[i].math >= 90)
			printf(" GREAT");
		if( arr[i].korea <70 || arr[i].eng < 70 || arr[i].math < 80)
			printf(" BAD");
		printf("\n");
	}
	return 0;
}