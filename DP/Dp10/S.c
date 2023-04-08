#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 2
#define M 3

int minSumPath(int n, int m, int matrix[N][M]) {
    int prev[M];
    int i, j, up, left;

    for (i = 0; i < m; i++)
        prev[i] = matrix[0][i];

    for (i = 1; i < n; i++) {
        int temp[M];

        for (j = 0; j < m; j++) {
            if (j == 0)
                temp[j] = matrix[i][j] + prev[j];
            else {
                up = matrix[i][j] + prev[j];
                left = matrix[i][j] + temp[j - 1];
                temp[j] = (up < left) ? up : left;
            }
        }
        for (j = 0; j < m; j++)
            prev[j] = temp[j];
    }

    return prev[m - 1];
}

int main() {
    int matrix[N][M] = {{5, 9, 6}, {11, 5, 2}};
    int n = N, m = M;

    printf("%d\n", minSumPath(n, m, matrix));
    return 0;
}
