#include <stdio.h>

const int N = 5;

int main() {
    int a[N][N];
    int value = 1;
    int min_row = 0, max_row = N - 1;
    int min_col = 0, max_col = N - 1;
    int i, j;
    while (value <= N * N) {
        for (i = min_col; i <= max_col && value <= N * N; i++) {
            a[min_row][i] = value++;
        }
        min_row++;

        for (i = min_row; i <= max_row && value <= N * N; i++) {
            a[i][max_col] = value++;
        }
        max_col--;

        for (i = max_col; i >= min_col && value <= N * N; i--) {
            a[max_row][i] = value++;
        }
        max_row--;

        for (i = max_row; i >= min_row && value <= N * N; i--) {
            a[i][min_col] = value++;
        }
        min_col++;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}