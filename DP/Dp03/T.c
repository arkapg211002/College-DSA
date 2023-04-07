#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int height[] = {30, 10, 60, 10, 60, 50};
    int n = sizeof(height) / sizeof(height[0]);
    int dp[n];
    int jumpOne, jumpTwo;
    int ind;

    for (ind = 0; ind < n; ind++) {
        dp[ind] = -1;
    }

    dp[0] = 0;

    for (ind = 1; ind < n; ind++) {
        jumpTwo = INT_MAX;
        jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
        if (ind > 1) {
            jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
        }
        dp[ind] = (jumpOne < jumpTwo) ? jumpOne : jumpTwo;
    }

    printf("%d", dp[n - 1]);

    return 0;
}
