#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

bool subsetSumUtil(int ind, int target, int arr[], int dp[][MAX_SIZE]) {
    if (target == 0) {
        return true;
    }

    if (ind == 0) {
        return arr[0] == target;
    }

    if (dp[ind][target] != -1) {
        return dp[ind][target] == 0 ? false : true;
    }

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target) {
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }

    dp[ind][target] = notTaken || taken ? 1 : 0;
    return notTaken || taken;
}

bool subsetSumToK(int n, int k, int arr[]) {
    int dp[MAX_SIZE][MAX_SIZE];
    memset(dp, -1, sizeof(dp));

    return subsetSumUtil(n - 1, k, arr, dp);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSumToK(n, k, arr)) {
        printf("Subset with given target found\n");
    } else {
        printf("Subset with given target not found\n");
    }

    return 0;
}
