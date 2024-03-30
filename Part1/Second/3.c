#include <stdio.h>

//
// Created by bogdan on 08.03.24.
//
const int N=5;
int main(){
    int a[N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            a[i][j]=0;
        }
    }
    for(j=0;j<N;j++){
        for(i=N-1;i>=N-1-j;i--){
            a[i][j]=1;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}