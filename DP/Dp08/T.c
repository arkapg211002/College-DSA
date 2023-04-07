#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWaysUtil(int m, int n, int dp[m][n]) {
    int i, j, up, left;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            
            up = (i > 0) ? dp[i-1][j] : 0;
            left = (j > 0) ? dp[i][j-1] : 0;
            
            dp[i][j] = up + left;
        }
    }
    
    return dp[m-1][n-1];
}

int countWays(int m, int n){
    int dp[m][n];
    memset(dp, -1, sizeof(dp));
    return countWaysUtil(m, n, dp);
}

int main(void) {
    int m = 3;
    int n = 2;
  
    printf("%d", countWays(m, n));
    
    return 0;
}
