#include <stdio.h>
#include <stdbool.h>

bool subsetSumToK(int n, int k, int arr[]) {

    bool dp[n][k + 1];

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSumToK(n, k, arr))
        printf("Subset with given target found\n");
    else
        printf("Subset with given target not found\n");

    return 0;
}
