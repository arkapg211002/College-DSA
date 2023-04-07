#include <stdio.h>

int countWaysUtil(int i, int j, int dp[][100]) {
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int countWays(int m, int n) {
    int dp[100][100];
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    return countWaysUtil(m - 1, n - 1, dp);
}

int main() {
    int m = 3;
    int n = 2;

    printf("%d\n", countWays(m, n));
    return 0;
}
