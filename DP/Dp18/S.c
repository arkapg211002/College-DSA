#include <stdio.h>

#define MOD 1000000007

int findWays(int num[], int n, int tar) {
    int dp[n][tar + 1];
    int i, j;
    
    if (num[0] == 0) {
        dp[0][0] = 2;
    } else {
        dp[0][0] = 1;
    }

    if (num[0] != 0 && num[0] <= tar) {
        dp[0][num[0]] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j <= tar; j++) {
            int notTaken = dp[i - 1][j];
            int taken = 0;

            if (num[i] <= j) {
                taken = dp[i - 1][j - num[i]];
            }
            dp[i][j] = (notTaken + taken) % MOD;
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int arr[], int n, int d) {
    int totSum = 0;
    int i;

    for (i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2 == 1) {
        return 0;
    }

    return findWays(arr, n, (totSum - d) / 2);
}

int main() {
    int arr[] = {5, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;

    printf("The number of subsets found are %d\n", countPartitions(arr, n, d));
    return 0;
}
