#include <stdio.h>
#include <stdlib.h>

int minSubsetSumDifference(int *arr, int n) {
    int totSum = 0;

    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    int *prev = (int *) calloc(totSum + 1, sizeof(int));
    prev[0] = 1;

    if (arr[0] <= totSum)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        int *cur = (int *) calloc(totSum + 1, sizeof(int));
        cur[0] = 1;
        for (int target = 1; target <= totSum; target++) {
            int notTaken = prev[target];

            int taken = 0;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }
        free(prev);
        prev = cur;
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (prev[i] == 1) {
            int diff = abs(i - (totSum - i));
            mini = (diff < mini) ? diff : mini;
        }
    }
    free(prev);
    return mini;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The minimum absolute difference is: %d", minSubsetSumDifference(arr, n));
    return 0;
}
