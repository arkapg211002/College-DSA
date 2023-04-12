#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 100005

int max(int a, int b) {
    return (a > b) ? a : b;
}

int stockProfit(int Arr[], int n)
{
    int dp[MAXN][2];
    memset(dp, 0, sizeof(dp));

    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit=0;

            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }

            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+2][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

int main()
{
    int prices[]= {4,9,0,4,10};
    int n = sizeof(prices)/sizeof(prices[0]);

    printf("The maximum profit that can be generated is %d\n", stockProfit(prices, n));

    return 0;
}
