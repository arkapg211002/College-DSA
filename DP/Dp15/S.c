#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 500

bool canPartition(int n, int arr[]) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }
    if (totSum % 2 == 1) return false;
    else {
        int k = totSum / 2;
        bool* prev = (bool*) calloc(k + 1, sizeof(bool));
        if (prev == NULL) exit(1);
        prev[0] = true;
        if (arr[0] <= k) prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            bool* cur = (bool*) calloc(k + 1, sizeof(bool));
            if (cur == NULL) exit(1);
            cur[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTaken = prev[target];
                bool taken = false;
                if (arr[ind] <= target) taken = prev[target - arr[ind]];
                cur[target] = notTaken || taken;
            }
            free(prev);
            prev = cur;
        }
        bool result = prev[k];
        free(prev);
        return result;
    }
}

int main() {
    int arr[] = {2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    if (canPartition(n, arr)) {
        printf("The Array can be partitioned into two equal subsets\n");
    } else {
        printf("The Array cannot be partitioned into two equal subsets\n");
    }
    return 0;
}
