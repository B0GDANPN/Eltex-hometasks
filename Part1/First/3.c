//
// Created by bogdan on 08.03.24.
//
#include <stdio.h>

//
// Created by bogdan on 08.03.24.
//
int main() {
    int i, counter = 0;
    scanf("%d", &i);
    for (int j = 8 * sizeof(i); j >= 0; j--) {
        counter += (i >> j) & 1;
    }
    printf("%d", counter);
    return 0;
}