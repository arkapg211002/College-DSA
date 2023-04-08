#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

bool subsetSumUtil(int ind, int target, int arr[], int** dp, int n) {
    if (target == 0)
        return dp[ind][target]=true;

    if (ind == 0)
        return dp[ind][target] = arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp, n);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp, n);

    return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(int arr[], int n) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    int** dp = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*) malloc((totSum + 1) * sizeof(int));
        for (int j = 0; j <= totSum; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i <= totSum; i++) {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp, n);
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (dp[n - 1][i] == true) {
            int diff = abs(i - (totSum - i));
            mini = (diff < mini) ? diff : mini;
        }
    }

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return mini;
}

int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The minimum absolute difference is: %d\n", minSubsetSumDifference(arr, n));
    return 0;
}
