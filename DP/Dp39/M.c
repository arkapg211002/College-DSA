#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 100005

int getAns(int Arr[], int ind, int buy, int n, int dp[][2]){

    if(ind>=n) return 0; //base case

    if(dp[ind][buy]!=-1)
        return dp[ind][buy];

    int profit=0;

    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind]+getAns(Arr,ind+1,1,n,dp));
    }

    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind]+getAns(Arr,ind+2,0,n,dp));
    }

    return dp[ind][buy] = profit;
}

int stockProfit(int Arr[], int n)
{
    int dp[MAXN][2];
    memset(dp, -1, sizeof(dp));

    int ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

int main()
{
    int prices[]= {4,9,0,4,10};
    int n = sizeof(prices)/sizeof(prices[0]);

    printf("The maximum profit that can be generated is %d\n", stockProfit(prices, n));

    return 0;
}
