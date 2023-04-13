#include <stdio.h>

#define MAXN 1000

int dp[MAXN + 1][MAXN + 1];

int longestIncreasingSubsequence(int arr[], int n) {
    int i, j;

    for (i = n - 1; i >= 0; i--) {
        for (j = i - 1; j >= -1; j--) {
            int notTake = 0 + dp[i + 1][j + 1];

            int take = 0;

            if (j == -1 || arr[i] > arr[j]) {
                take = 1 + dp[i + 1][i + 1];
            }

            dp[i][j + 1] = (notTake > take ? notTake : take);
        }
    }

    return dp[0][0];
}

int main(void) {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The length of the longest increasing subsequence is %d\n", longestIncreasingSubsequence(arr, n));

    return 0;
}
