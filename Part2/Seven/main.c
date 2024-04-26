//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

/*
gcc add.c -c
gcc sub.c -c
gcc mul.c -c
gcc div.c -c
ar rc libcalc.a add.o sub.o mul.o div.o
gcc main.c -o main -L. -lcalc
*/
int main() {
    int switcher, a, b;
    while (1) {
        printf("\n--- Calculator Menu ---\n");
        printf("1) Add\n");
        printf("2) Sub\n");
        printf("3) Mul\n");
        printf("4) Div\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &switcher);
        switch (switcher) {
            case 1:
                scanf("%d %d", &a, &b);
                printf("%d\n", add(a, b));
                break;
            case 2:
                scanf("%d %d", &a, &b);
                printf("%d\n", sub(a, b));
                break;
            case 3:
                scanf("%d %d", &a, &b);
                printf("%d\n", mul(a, b));
                break;
            case 4:
                scanf("%d %d", &a, &b);
                if (b == 0) {
                    printf("Second value must be non zero\n");
                    break;
                }
                printf("%d\n", div(a, b));
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid switcher. Please try again.\n");
        }
    }
}