#include <stdio.h>
#include <limits.h>

#define ROWS 2
#define COLS 3

int minSumPath(int n, int m, int matrix[][COLS]) {
    int dp[ROWS][COLS];
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = matrix[i][j];
            } else {
                int up = matrix[i][j];
                if (i > 0) {
                    up += dp[i-1][j];
                } else {
                    up += INT_MAX;
                }
                
                int left = matrix[i][j];
                if (j > 0) {
                    left += dp[i][j-1];
                } else {
                    left += INT_MAX;
                }
                
                dp[i][j] = (up < left) ? up : left;
            }
        }
    }
    
    return dp[n-1][m-1];
}

int main() {
    int matrix[ROWS][COLS] = {{5, 9, 6}, {11, 5, 2}};
    int n = ROWS;
    int m = COLS;
    
    printf("%d\n", minSumPath(n, m, matrix));
    
    return 0;
}
