#include <stdio.h>
#include <stdlib.h>

int maximumProfit(int n, int fee, int Arr[]) {
    if(n==0) return 0;
    
    int dp[n+1][2];
    
    // base condition is handled by initializing dp array as 0
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            
            if(buy == 0){// We can buy the stock
                profit = (dp[ind+1][0] > (-Arr[ind] + dp[ind+1][1]) ? dp[ind+1][0] : -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy == 1){// We can sell the stock
                profit = (dp[ind+1][1] > (Arr[ind] - fee + dp[ind+1][0]) ? dp[ind+1][1] : Arr[ind] - fee + dp[ind+1][0]);
            }
            
            dp[ind][buy]  = profit;
        }
    }
    
    return dp[0][0];
}

int main() {
    int prices[] = {1, 3, 2, 8, 4, 9};
    int n = sizeof(prices) / sizeof(prices[0]);
    int fee = 2;

    printf("The maximum profit that can be generated is %d\n", maximumProfit(n, fee, prices));
    return 0;
}
