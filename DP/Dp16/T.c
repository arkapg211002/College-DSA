#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_SUM 10000

int minSubsetSumDifference(int arr[], int n) {
    int totSum = 0, dp[MAX_N][MAX_SUM] = {0};
    int i, j;

    for (i = 0; i < n; i++) {
        totSum += arr[i];
    }

    for (i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if (arr[0] <= totSum) {
        dp[0][arr[0]] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j <= totSum; j++) {
            int notTaken = dp[i-1][j];
            int taken = 0;
            if (arr[i] <= j) {
                taken = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTaken || taken;
        }
    }

    int mini = MAX_SUM;
    for (i = 0; i <= totSum; i++) {
        if (dp[n-1][i] == 1) {
            int diff = abs(i - (totSum - i));
            mini = (diff < mini) ? diff : mini;
        }
    }
    return mini;
}

int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The minimum absolute difference is: %d\n", minSubsetSumDifference(arr, n));

    return 0;
}
