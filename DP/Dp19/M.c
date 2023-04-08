#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int knapsackUtil(int wt[], int val[], int ind, int W, int dp[][W+1]) {

    if (ind == 0) {
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + knapsackUtil(wt, val, ind-1, W, dp);

    int taken = -1;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind-1, W-wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}


int knapsack(int wt[], int val[], int n, int W) {

    int dp[n][W+1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W+1; j++) {
            dp[i][j] = -1;
        }
    }

    return knapsackUtil(wt, val, n-1, W, dp);
}


int main() {

    int wt[] = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int W = 5;

    int n = sizeof(wt)/sizeof(wt[0]);

    printf("The Maximum value of items, thief can steal is %d", knapsack(wt, val, n, W));

    return 0;
}
