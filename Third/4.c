//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>
const int buf_size=4096;
char *strstr(char const *str, char const *pattern) {
    char *a, *b;
    b = pattern;
    if (*b =='\n') {
        return str;
    }
    for (; *str != '\n'; str ++) {
        if (*str != *b) {
            continue;
        }
        a = str;
        while (1) {
            if (*b == '\n') {
                return str;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = pattern;
    }
    return NULL;
}
int main() {
    char buf_string[buf_size], buf_substring[buf_size];
    fgets(buf_string, buf_size, stdin);
    fgets(buf_substring, buf_size, stdin);
    printf("%p", strstr(buf_string, buf_substring));
    return 0;
}