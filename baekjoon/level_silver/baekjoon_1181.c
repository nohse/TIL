#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char array[20000][51];

int stringcomp(char* brray, char* crray)
{
	int x = strlen(brray);
	int y = strlen(crray);
	if (x < y) return -1;
	else if (x > y) return 1;
	else
	{
		return strcmp(brray, crray);
	}
}

int main()
{
	int i, N;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", &array[i]);
	}
	qsort(array, N, 51 * sizeof(char), stringcomp);
	printf("%s\n", array[0]);
	for (i = 1; i < N; i++)
	{
		if (strcmp(array[i - 1], array[i])) printf("%s\n", array[i]);
	}
	return 0;
}