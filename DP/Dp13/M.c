#include <stdio.h>
#include <limits.h>
#include <math.h>

int maxChocoUtil(int i, int j1, int j2, int n, int m, int grid[n][m], int dp[n][m][m]) {
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return (int)pow(-10, 9);

    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            maxi = fmax(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, int grid[n][m]) {
    int dp[n][m][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}

int main() {
    int matrix[3][4] = {{2, 3, 1, 2},
                        {3, 4, 2, 2},
                        {5, 6, 3, 5}};
    int n = 3;
    int m = 4;

    printf("%d\n", maximumChocolates(n, m, matrix));

    return 0;
}
