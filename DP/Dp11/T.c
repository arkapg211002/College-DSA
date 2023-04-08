#include <stdio.h>
#include <limits.h>

int minSumPath(int n, int m, int matrix[n][m]) {
    int dp[n][m];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) dp[i][j] = matrix[i][j];
            else {
                int up = matrix[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += INT_MAX;
                
                int left = matrix[i][j];
                if(j > 0) left += dp[i][j-1];
                else left += INT_MAX;
                
                dp[i][j] = (up < left) ? up : left;
            }
        }
    }
    
    return dp[n-1][m-1];
}

int main() {
    int matrix[2][3] = {{5, 9, 6}, {11, 5, 2}};
    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    
    printf("%d", minSumPath(n, m, matrix));
    
    return 0;
}
