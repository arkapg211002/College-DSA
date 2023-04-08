#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

int min(int a, int b) {
    return a < b ? a : b;
}

int minSumPathUtil(int i, int j, int matrix[MAX_SIZE][MAX_SIZE], int dp[MAX_SIZE][MAX_SIZE], int n, int m) {
    if (i == 0 && j == 0) {
        return matrix[0][0];
    }
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = matrix[i][j] + minSumPathUtil(i-1, j, matrix, dp, n, m);
    int left = matrix[i][j] + minSumPathUtil(i, j-1, matrix, dp, n, m);
    return dp[i][j] = min(up, left);
}

int minSumPath(int n, int m, int matrix[MAX_SIZE][MAX_SIZE]) {
    int dp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }
    return minSumPathUtil(n-1, m-1, matrix, dp, n, m);
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = {{5, 9, 6}, {11, 5, 2}};
    int n = sizeof(matrix)/sizeof(matrix[0]);
    int m = sizeof(matrix[0])/sizeof(matrix[0][0]);
    printf("%d", minSumPath(n, m, matrix));
    return 0;
}
