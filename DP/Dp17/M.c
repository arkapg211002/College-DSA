#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findWaysUtil(int ind, int target, int arr[], int dp[][4]) {
    if (target == 0)
        return 1;

    if (ind == 0)
        return arr[0] == target ? 1 : 0;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

int findWays(int num[], int k) {
    int n = sizeof(num) / sizeof(num[0]);
    int dp[n][k + 1];
    memset(dp, -1, sizeof(dp));

    return findWaysUtil(n - 1, k, num, dp);
}

int main() {
    int arr[] = {1, 2, 2, 3};
    int k = 3;

    printf("The number of subsets found are %d\n", findWays(arr, k));
    return 0;
}
