#include <stdio.h>

#define MAXN 1000

int dp[MAXN][MAXN + 1];

int getAns(int arr[], int n, int ind, int prev_index) {
    // base condition
    if (ind == n) {
        return 0;
    }

    if (dp[ind][prev_index + 1] != -1) {
        return dp[ind][prev_index + 1];
    }

    int notTake = 0 + getAns(arr, n, ind + 1, prev_index);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind);
    }

    return dp[ind][prev_index + 1] = (notTake > take ? notTake : take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    return getAns(arr, n, 0, -1);
}

int main(void) {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The length of the longest increasing subsequence is %d\n", longestIncreasingSubsequence(arr, n));

    return 0;
}
