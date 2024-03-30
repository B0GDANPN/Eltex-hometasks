//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>

int main() {
    int num;
    int tmp;
    scanf("%d\n", &num);
    char *bytePtr;
    scanf("%d", &tmp);
    char byte =(char)tmp%128;
    bytePtr = (char*)&num;
    bytePtr[2] = byte;
    printf("%d", num);

    return 0;
}