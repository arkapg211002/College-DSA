#include <stdio.h>

#define MAX_SIZE 100

int solveUtil(int ind, int arr[], int dp[]);
int solve(int n, int arr[]);

int main() {
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", solve(n, arr));
    return 0;
}

int solveUtil(int ind, int arr[], int dp[]) {
    if (ind < 0)  return 0;
    if (ind == 0) return arr[ind];
    if (dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);

    dp[ind] = (pick > nonPick) ? pick : nonPick;
    return dp[ind];
}

int solve(int n, int arr[]) {
    int dp[MAX_SIZE];
    int i;

    for (i = 0; i < n; i++) {
        dp[i] = -1;
    }

    return solveUtil(n - 1, arr, dp);
}
