#include <stdio.h>
#include <stdbool.h>

bool subsetSumUtil(int ind, int target, int arr[], int dp[][1001]) {
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target] == 0 ? false : true;

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    dp[ind][target] = notTaken || taken ? 1 : 0;
    return notTaken || taken;
}

bool canPartition(int n, int arr[]) {

    int totSum = 0;

    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;
        int dp[n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }
        return subsetSumUtil(n - 1, k, arr, dp);
    }
}

int main() {
    int arr[] = {2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(n, arr))
        printf("The Array can be partitioned into two equal subsets\n");
    else
        printf("The Array cannot be partitioned into two equal subsets\n");

    return 0;
}
