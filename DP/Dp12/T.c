#include <stdio.h>
#include <limits.h>

#define ROWS 4
#define COLS 4

int getMaxPathSum(int matrix[ROWS][COLS]) {
    int dp[ROWS][COLS] = {0};
    
    // Initializing first row - base condition
    for(int j=0; j<COLS; j++) {
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += INT_MIN;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<COLS) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += INT_MIN;
            
            dp[i][j] = (up > leftDiagonal) ? (up > rightDiagonal ? up : rightDiagonal) : (leftDiagonal > rightDiagonal ? leftDiagonal : rightDiagonal);
        }
    }
    
    int maxi = INT_MIN;
    for(int j=0; j<COLS; j++) {
        maxi = (maxi > dp[ROWS-1][j]) ? maxi : dp[ROWS-1][j];
    }
    
    return maxi;
}

int main() {
    int matrix[ROWS][COLS] = {{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
    printf("%d", getMaxPathSum(matrix));
    return 0;
}
