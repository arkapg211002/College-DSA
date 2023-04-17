#include <stdio.h>
#include <limits.h>

#define MAX_N 100

int f(int arr[], int i, int j, int dp[][MAX_N]) {
    // base condition
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++) {
        int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

        mini = (ans < mini) ? ans : mini;
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(int arr[], int N) {
    int dp[MAX_N][MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dp[i][j] = -1;
        }
    }

    int i = 1;
    int j = N - 1;

    return f(arr, i, j, dp);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The minimum number of operations are %d\n", matrixMultiplication(arr, n));

    return 0;
}
