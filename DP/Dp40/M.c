#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getAns(int Arr[], int ind, int buy, int n, int fee, int dp[][2])
{
    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit=0;
    
    if(buy==0){ // We can buy the stock
        profit = (0+getAns(Arr,ind+1,0,n,fee,dp) > -Arr[ind] + getAns(Arr,ind+1,1,n,fee,dp)) ? 0+getAns(Arr,ind+1,0,n,fee,dp) : -Arr[ind] + getAns(Arr,ind+1,1,n,fee,dp);
    }
    
    if(buy==1){ // We can sell the stock
        profit = (0+getAns(Arr,ind+1,1,n,fee,dp) > Arr[ind] -fee + getAns(Arr,ind+1,0,n,fee,dp)) ? 0+getAns(Arr,ind+1,1,n,fee,dp) : Arr[ind] -fee + getAns(Arr,ind+1,0,n,fee,dp);
    }
    
    return dp[ind][buy] = profit;
}

int maximumProfit(int n, int fee, int Arr[])
{
    int dp[n][2];
    memset(dp, -1, sizeof(dp)); // Initialize all values to -1
    
    if(n==0) return 0;
    int ans = getAns(Arr,0,0,n,fee,dp);
    return ans;
}

int main()
{
    int prices[] = {1,3,2,8,4,9};
    int n = sizeof(prices) / sizeof(prices[0]);
    int fee = 2;
                                 
    printf("The maximum profit that can be generated is %d\n", maximumProfit(n,fee,prices));
    return 0;
}
