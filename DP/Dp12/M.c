#include <stdio.h>
#include <limits.h>

#define N 4
#define M 4

int getMaxUtil(int i, int j, int m, int matrix[][M], int dp[][M]) {
    if (j < 0 || j >= m) {
        return INT_MIN;
    }
    if (i == 0) {
        return matrix[0][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);
    dp[i][j] = up > leftDiagonal ? (up > rightDiagonal ? up : rightDiagonal) : (leftDiagonal > rightDiagonal ? leftDiagonal : rightDiagonal);
    return dp[i][j];
}

int getMaxPathSum(int matrix[][M]) {
    int dp[N][M];
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            dp[i][j] = -1;
        }
    }
    int maxi = INT_MIN;
    for (j = 0; j < M; ++j) {
        int ans = getMaxUtil(N - 1, j, M, matrix, dp);
        maxi = ans > maxi ? ans : maxi;
    }
    return maxi;
}

int main() {
    int matrix[N][M] = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    printf("%d\n", getMaxPathSum(matrix));
    return 0;
}
