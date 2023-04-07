#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int solveUtil(int ind, int height[], int dp[], int k) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int mmSteps = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = jump < mmSteps ? jump : mmSteps;
        }
    }

    return dp[ind] = mmSteps;
}

int solve(int n, int height[], int k) {
    int *dp = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    int res = solveUtil(n - 1, height, dp, k);
    free(dp);
    return res;
}

int main() {
    int height[] = {30, 10, 60, 10, 60, 50};
    int n = sizeof(height) / sizeof(height[0]);
    int k = 2;

    printf("%d\n", solve(n, height, k));

    return 0;
}
