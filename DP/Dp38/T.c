#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100
#define MAX_K 10

int max(int a, int b) {
    return a > b ? a : b;
}

int maximumProfit(int Arr[], int n, int k)
{
    int dp[MAX_N + 1][2][MAX_K + 1];
    int ind, buy, cap;

    for (ind = 0; ind <= n; ind++) {
        for (buy = 0; buy <= 1; buy++) {
            for (cap = 0; cap <= k; cap++) {
                dp[ind][buy][cap] = 0;
            }
        }
    }

    for (ind = n - 1; ind >= 0; ind--) {
        for (buy = 0; buy <= 1; buy++) {
            for (cap = 1; cap <= k; cap++) {
                int profit = 0;
                if (buy == 0) {
                    profit = max(0 + dp[ind + 1][0][cap],
                                 -Arr[ind] + dp[ind + 1][1][cap]);
                } else {
                    profit = max(0 + dp[ind + 1][1][cap],
                                 Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }

    return dp[0][0][k];
}

int main()
{
    int Arr[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int k = 2;
    printf("The maximum profit that can be generated is %d\n", maximumProfit(Arr, n, k));
    return 0;
}
