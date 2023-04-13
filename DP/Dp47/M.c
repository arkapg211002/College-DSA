#include <stdio.h>

int findNumberOfLIS(int arr[], int n) {

    int dp[n], ct[n];
    int maxi = 1, nos = 0;

    for(int i = 0; i < n; i++) {
        dp[i] = ct[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int prev_index = 0; prev_index < i; prev_index++) {

            if(arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i]) {
                dp[i] = dp[prev_index] + 1;
                ct[i] = ct[prev_index];
            }
            else if(arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i]) {
                ct[i] += ct[prev_index];
            }
        }
        maxi = maxi > dp[i] ? maxi : dp[i];
    }

    for(int i = 0; i < n; i++) {
        if(dp[i] == maxi) nos += ct[i];
    }

    return nos;
}

int main() {

    int arr[] = {1,5,4,3,2,6,7,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The count of LIS is %d", findNumberOfLIS(arr, n));

    return 0;
}
