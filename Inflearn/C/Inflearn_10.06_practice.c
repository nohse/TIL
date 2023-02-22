#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MONTHS 12
#define YEARS 3
int main() {

	double TempData[YEARS][MONTHS] = { {-3.2,0.2,7.0,14.1,19.6,23.6,26.2,28.0,23.1,16.1,6.8,1.2},
		{-1.8,-0.2,6.3,13.9,19.5,23.3,26.9,25.9,22.1,16.4,5.6,-1.9}
	,{-4.0,-1.6,8.1,13.0,18.2,23.1,27.8,28.8,21.5,13.1,7.8,-0.6} };

	int i, j;
	printf("[Temperature Data]\n");
	printf("Year index : ");
	for (i = 1; i <= MONTHS; i++)
		printf("\t%d", i);
	printf("\n");
	for (j = 0; j < YEARS; j++) {
		printf("Year %d     :", j);
		for (i = 0; i < MONTHS; i++) {
			printf("\t%.1lf", TempData[j][i]);
		}
		printf("\n");
	}
	printf("\n");

	printf("[Yearly average temperatures of 3 years]\n");
	for (int j = 0; j < YEARS; j++) {
		double avg_temp = 0.0;

		for (int i = 0; i < MONTHS; i++) {
			avg_temp += TempData[j][i];
		}

		avg_temp /= (double)MONTHS;

		printf("Year %d : average temperature = %.1f\n", j, avg_temp);
	}
	printf("\n");

	printf("Avg temps  :");
	for (i = 0; i < MONTHS; i++) {
		double avg_temp = 0;
		for (j = 0; j < YEARS; j++) {
			avg_temp += TempData[j][i];
		}
		avg_temp /= (double)YEARS;
		printf("\t%.1f", avg_temp);

	}
	printf("\n");
}