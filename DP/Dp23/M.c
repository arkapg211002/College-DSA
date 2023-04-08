#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int knapsackUtil(int wt[], int val[], int ind, int W, int **dp) {
    if(ind == 0) {
        return (W / wt[0]) * val[0];
    }
    
    if(dp[ind][W] != -1) {
        return dp[ind][W];
    }
    
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = INT_MIN;
    
    if(wt[ind] <= W) {
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
    }
        
    return dp[ind][W] = (notTaken > taken) ? notTaken : taken;
}

int unboundedKnapsack(int n, int W, int val[], int wt[]) {
    int **dp = (int **)malloc(n * sizeof(int *));
    
    for(int i = 0; i < n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
        for(int j = 0; j <= W; j++) {
            dp[i][j] = -1;
        }
    }
    
    int result = knapsackUtil(wt, val, n - 1, W, dp);
    
    for(int i = 0; i < n; i++) {
        free(dp[i]);
    }
    
    free(dp);
    
    return result;
}

int main() {
    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int W = 10;
    int n = sizeof(wt) / sizeof(wt[0]);
    
    printf("The maximum value of items, thief can steal is %d", unboundedKnapsack(n, W, val, wt));
    
    return 0;
}
