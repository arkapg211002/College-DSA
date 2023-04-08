#include <stdio.h>
#include <limits.h>

#define min(a,b) ((a)<(b)?(a):(b))

int minimumPathSumUtil(int i, int j, int triangle[][j+1], int n, int dp[][j+1]) {
    if(dp[i][j]!=-1)
        return dp[i][j];
  
    if(i==n-1)
        return triangle[i][j];
    
    int down = triangle[i][j] + minimumPathSumUtil(i+1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i+1, j+1, triangle, n, dp);
  
    return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(int triangle[][n], int n) {
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = -1;
        }
    }
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

int main() {
    int triangle[][4] = {{1},
                         {2,3},
                         {3,6,7},
                         {8,9,6,10}};
                            
    int n = sizeof(triangle)/sizeof(triangle[0]);
  
    printf("%d", minimumPathSum(triangle, n));
    
    return 0;
}
