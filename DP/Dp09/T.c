#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mazeObstaclesUtil(int n, int m, int maze[][m], int dp[][m]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            // base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1];
}

int mazeObstacles(int n, int m, int maze[][m]) {
    int dp[n][m];
    memset(dp, -1, sizeof(dp)); // initialize to -1

    return mazeObstaclesUtil(n, m, maze, dp);
}

int main() {
    int maze[][3] = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    int n = 3;
    int m = 3;

    printf("%d\n", mazeObstacles(n, m, maze));
    return 0;
}
