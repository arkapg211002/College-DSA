#include <stdio.h>
#include <stdlib.h>

long countWaysToMakeChangeUtil(int arr[], int ind, int T, long **dp) {
    if (ind == 0) {
        if (T % arr[0] == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[ind][T] != -1) {
        return dp[ind][T];
    }

    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);

    long taken = 0;
    if (arr[ind] <= T) {
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
    }

    return dp[ind][T] = notTaken + taken;
}

long countWaysToMakeChange(int arr[], int n, int T) {
    long **dp = (long **)malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        dp[i] = (long *)malloc((T + 1) * sizeof(long));
        for (int j = 0; j <= T; j++) {
            dp[i][j] = -1;
        }
    }

    long result = countWaysToMakeChangeUtil(arr, n - 1, T, dp);

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int arr[] = {1, 2, 3};
    int target = 4;

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The total number of ways is %ld", countWaysToMakeChange(arr, n, target));

    return 0;
}
