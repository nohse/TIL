#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct time {
	int hour;
	int minute;
	int second;

}t;

int main() {
	struct time a;
	struct time b;
	int totalsec_a;
	int totalsec_b;
	int diff_sec;
	scanf("%d %d %d", &a.hour, &a.minute, &a.second);
	scanf("%d %d %d", &b.hour, &b.minute, &b.second);
	totalsec_a = a.hour * 3600 + a.minute * 60 + a.second;
	totalsec_b = b.hour * 3600 + b.minute * 60 + b.second;
	diff_sec = totalsec_b - totalsec_a;
	printf("%d %d %d", diff_sec / 3600, diff_sec % 3600 / 60, diff_sec % 60);

	return 0;
}