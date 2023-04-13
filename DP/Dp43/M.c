#include <stdio.h>
#include <stdlib.h>

int getAns(int arr[], int n, int ind, int prev_index, int** dp) {

    if(ind == n) {
        return 0;
    }
    
    if(dp[ind][prev_index+1] != -1) {
        return dp[ind][prev_index+1];
    }

    int notTake = 0 + getAns(arr, n, ind+1, prev_index, dp);

    int take = 0;

    if(prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind+1, ind, dp);
    }

    return dp[ind][prev_index+1] = (notTake > take ? notTake : take);
}

int longestIncreasingSubsequence(int arr[], int n) {

    int** dp = (int**)malloc((n+1) * sizeof(int*));
    for(int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((n+1) * sizeof(int));
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = getAns(arr, n, 0, -1, dp);

    for(int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return ans;
}

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The length of the longest increasing subsequence is %d", longestIncreasingSubsequence(arr, n));

    return 0;
}
