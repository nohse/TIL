#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int cnt_char(const char* str, char ch);

int main() {
    char str[101], ch;
    scanf("%s", str);
    getchar();
    scanf("%c", &ch);
    printf("%d", cnt_char(str, ch));
    return 0;
}

int cnt_char(const char* str, char ch) {
    if (*str == '\0') {
        return 0;
    }
    if (*str == ch) { 
        return 1 + cnt_char(str + 1, ch);
    }
    else { 
        return cnt_char(str + 1, ch);
    }
}