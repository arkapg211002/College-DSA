#include <stdio.h>

int countPartitionsUtil(int ind, int target, int arr[], int dp[][100]) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken);
}

int targetSum(int n, int target, int arr[]) {
    int totSum = 0;
    int dp[n][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0)
        return 0;
    if ((totSum - target) % 2 == 1)
        return 0;

    int s2 = (totSum - target) / 2;

    return countPartitionsUtil(n - 1, s2, arr, dp);
}

int main() {
    int arr[] = {1, 2, 3, 1};
    int target = 3;

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The number of ways found is %d", targetSum(n, target, arr));
    return 0;
}
