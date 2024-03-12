#include <stdio.h>

//
// Created by bogdan on 12.03.24.
//
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    while ((*a)<11){
        printf("%d ",*a);
        (*a)++;
    }
    return 0;
}