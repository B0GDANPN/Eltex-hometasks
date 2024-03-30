//
// Created by bogdan on 08.03.24.
//
#include <stdio.h>
const size_t shift = 16;
int main() {
    unsigned int l, r;
    scanf("%d %d", &l, &r);
    r &=0xFF;

    unsigned int mask = ~(0xFF << shift);
    l&=mask;

    l|= (r << shift);
    printf("%u", l);
    return 0;
}