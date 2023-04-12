#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1000
#define MAX_BUY 2
#define MAX_CAP 3

int getAns(int* Arr, int n, int ind, int buy, int cap, int dp[MAX_N][MAX_BUY][MAX_CAP]) {
    if (ind == n || cap == 0) {
        return 0;
    }
    
    if (dp[ind][buy][cap] != -1) {
        return dp[ind][buy][cap];
    }
        
    int profit;
    
    if (buy == 0) {// We can buy the stock
        profit = (0 + getAns(Arr, n, ind + 1, 0, cap, dp) > -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp)) ?
                 0 + getAns(Arr, n, ind + 1, 0, cap, dp) : -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp);
    }
    
    if (buy == 1) {// We can sell the stock
        profit = (0 + getAns(Arr, n, ind + 1, 1, cap, dp) > Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp)) ?
                 0 + getAns(Arr, n, ind + 1, 1, cap, dp) : Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp);
    }
    
    return dp[ind][buy][cap] = profit;
}

int maxProfit(int* prices, int n) {
    // Creating a 3d - dp of size [n][2][3]
    int dp[MAX_N][MAX_BUY][MAX_CAP];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_BUY; j++) {
            for (int k = 0; k < MAX_CAP; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    return getAns(prices, n, 0, 0, 2, dp);
}

int main() {
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
                                 
    printf("The maximum profit that can be generated is %d\n", maxProfit(prices, n));
    
    return 0;
}
