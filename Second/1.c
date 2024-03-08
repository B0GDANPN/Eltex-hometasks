#include <stdio.h>

//
// Created by bogdan on 08.03.24.
//
const int N=5;
int main(){
    int a[N][N];
    int i,j,c=1;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            a[i][j]=c;
            c++;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}