#include <stdio.h>
#include <stdlib.h>

int longestBitonicSequence(int arr[], int n) {
    int dp1[n], dp2[n];
    for (int i = 0; i < n; i++) {
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i]) {
                dp1[i] = (dp1[i] > (1 + dp1[prev_index])) ? dp1[i] : (1 + dp1[prev_index]);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int prev_index = n - 1; prev_index > i; prev_index--) {
            if (arr[prev_index] < arr[i]) {
                dp2[i] = (dp2[i] > (1 + dp2[prev_index])) ? dp2[i] : (1 + dp2[prev_index]);
            }
        }
    }

    int maxi = -1;

    for (int i = 0; i < n; i++) {
        if (dp1[i] + dp2[i] - 1 > maxi) {
            maxi = dp1[i] + dp2[i] - 1;
        }
    }

    return maxi;
}

int main() {
    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The length of the longest bitonic subsequence is %d\n", longestBitonicSequence(arr, n));

    return 0;
}
