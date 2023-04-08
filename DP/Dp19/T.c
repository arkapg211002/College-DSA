#include <stdio.h>

#define MAX_N 100
#define MAX_W 100

int knapsack(int wt[], int val[], int n, int W) {
    int dp[MAX_N][MAX_W+1];

    // Base Condition
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind=1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = -2147483647;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = (notTaken > taken) ? notTaken : taken;
        }
    }
    
    return dp[n-1][W];
}

int main() {
    int wt[] = {1,2,4,5};
    int val[] = {5,4,8,6};
    int W = 5;
    int n = sizeof(wt)/sizeof(wt[0]);
    
    printf("The Maximum value of items, thief can steal is %d\n", knapsack(wt, val, n, W));

    return 0;
}
