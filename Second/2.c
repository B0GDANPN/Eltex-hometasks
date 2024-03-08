#include <stdio.h>

//
// Created by bogdan on 08.03.24.
//
const int N=5;
int main(){
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for (int i = N-1; i>=0 ; i--) {
        printf("%d ",a[i]);

    }
}