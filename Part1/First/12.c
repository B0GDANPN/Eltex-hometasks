#include <stdio.h>

//
// Created by bogdan on 08.03.24.
//
int main() {
    int i;
    scanf("%d", &i);
    for (int j = 8 * sizeof(i); j >= 0; j--) {
        printf("%d", (i >> j) & 1);
    }
    return 0;
}