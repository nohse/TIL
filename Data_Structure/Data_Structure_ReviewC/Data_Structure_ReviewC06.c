#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define STUDENT_NUM 5
struct student_inform {
	char name[10];
	int score;
}S;
int main() {
	struct student_inform arr[STUDENT_NUM];
	int i;
	float avg = 0.0;
	for (i = 0; i < STUDENT_NUM; i++) {
		scanf("%s %d", arr[i].name, &arr[i].score);
		avg += arr[i].score;
	}
	avg /= STUDENT_NUM;
	for (i = 0; i < STUDENT_NUM; i++) {
		if (arr[i].score <= avg)
			printf("%s\n", arr[i].name);

	}
}
