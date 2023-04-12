#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100000

long getAns(long *Arr, int ind, int buy, int n, long dp[MAX_N][2])
{
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit;
    
    if (buy == 0) {
        profit = fmax(0 + getAns(Arr, ind + 1, 0, n, dp),
                      -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }
    
    if (buy == 1) {
        profit = fmax(0 + getAns(Arr, ind + 1, 1, n, dp),
                      Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }
    
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n)
{
    long dp[MAX_N][2];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    
    if (n == 0) {
        return 0;
    }
    
    long ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};
    
    printf("The maximum profit that can be generated is %ld\n", getMaximumProfit(Arr, n));
    
    return 0;
}
