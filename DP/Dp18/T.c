#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mod (int)(pow(10,9)+7)

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

    int notTaken = countPartitionsUtil(ind-1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken) % mod;
}

int countPartitions(int d, int arr[], int n) {
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    // Checking for edge cases
    if (totSum - d < 0) return 0;
    if ((totSum - d) % 2 == 1) return 0;

    int s2 = (totSum - d) / 2;

    int dp[100][100];
    memset(dp, -1, sizeof(dp));

    return countPartitionsUtil(n-1, s2, arr, dp);
}

int main() {
    int arr[] = {5, 2, 6, 4};
    int d = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The number of subsets found are %d\n", countPartitions(d, arr, n));

    return 0;
}
