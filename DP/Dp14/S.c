#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool subsetSumToK(int n, int k, int arr[]) {
    bool prev[k+1];
    for(int i = 0; i <= k; i++) {
        prev[i] = false;
    }

    prev[0] = true;

    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++) {
        bool cur[k+1];
        cur[0] = true;
        for (int j = 1; j <= k; j++) {
            bool notTaken = prev[j];
            bool taken = false;
            if (arr[i] <= j) {
                taken = prev[j-arr[i]];
            }
            cur[j] = notTaken || taken;
        }
        for (int j = 0; j <= k; j++) {
            prev[j] = cur[j];
        }
    }
    return prev[k];
}

int main() {
    int arr[] = {1,2,3,4};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSumToK(n, k, arr)) {
        printf("Subset with given target found\n");
    } else {
        printf("Subset with given target not found\n");
    }

    return 0;
}
