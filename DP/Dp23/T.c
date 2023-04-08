#include <stdio.h>
#include <limits.h>

int unboundedKnapsack(int n, int W, int val[], int wt[]) {
    int dp[n][W+1];
    
    // Initializing base condition
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = (i/wt[0]) * val[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int cap = 0; cap <= W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = (notTaken > taken) ? notTaken : taken;
        }
    }
    
    return dp[n-1][W];
}

int main() {
    int wt[] = {2,4,6};
    int val[] = {5,11,13};
    int W = 10;
    
    int n = sizeof(wt)/sizeof(wt[0]);
                                 
    printf("The Maximum value of items, thief can steal is %d\n",
        unboundedKnapsack(n, W, val, wt));
    
    return 0;
}
