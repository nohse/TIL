#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isalpha �Լ��� ����ϱ� ���� �߰�

int main() {
    char sentence[1000001];
    char maxkey;
    int maxcnt = 0, cnt = 0;

    scanf("%s", sentence);

    // �Է� ���ڿ��� ���� ���
    int len = strlen(sentence);

    // ���ڿ��� ��� �빮�ڷ� ��ȯ
    for (int i = 0; i < len; i++) {
        sentence[i] = toupper(sentence[i]);
    }

    // ���ĺ� �� ������ ���� ���� ���� ������ ���ĺ��� ã��
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