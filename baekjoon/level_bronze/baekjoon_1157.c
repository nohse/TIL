#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isalpha 함수를 사용하기 위해 추가

int main() {
    char sentence[1000001];
    char maxkey;
    int maxcnt = 0, cnt = 0;

    scanf("%s", sentence);

    // 입력 문자열의 길이 계산
    int len = strlen(sentence);

    // 문자열을 모두 대문자로 변환
    for (int i = 0; i < len; i++) {
        sentence[i] = toupper(sentence[i]);
    }

    // 알파벳 별 개수를 세고 가장 많이 나오는 알파벳을 찾음
    for (int i = 'A'; i <= 'Z'; i++) {
        cnt = 0;
        for (int j = 0; j < len; j++) {
            if (sentence[j] == i)
                cnt++;
        }
        if (maxcnt < cnt) {
            maxcnt = cnt;
            maxkey = i;
        }
        else if (maxcnt == cnt) {
            maxkey = '?';
        }
    }

    printf("%c", maxkey);

    return 0;
}