//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
int main() {
    int switcher;
    int a,b,out;
    while (1) {
        printf("\n--- Calculator Menu ---\n");
        printf("1) Add\n");
        printf("2) Sub\n");
        printf("3) Mul\n");
        printf("4) Div\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &switcher);
        getchar();
        scanf("%d %d\n",&a,&b);
        switch (switcher) {
            case 1:
                out=add(a,b);
                printf("%d\n",out);
                break;
            case 2:
                out=sub(a,b);
                printf("%d\n",out);
                break;
            case 3:
                out=mul(a,b);
                printf("%d\n",out);
                break;
            case 4:
                if (b==0){
                    printf("Second value must be non zero\n");
                    break;
                }
                out= div(a,b);
                printf("%d\n",out);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid switcher. Please try again.\n");
        }
    }
}