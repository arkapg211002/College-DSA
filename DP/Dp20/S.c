#include <stdio.h>
#include <limits.h>

int minimumElementsUtil(int arr[], int ind, int T, int dp[][T+1]){
    if (ind == 0) {
        if (T % arr[0] == 0) {
            return T / arr[0];
        }
        else {
            return INT_MAX;
        }
    }
    if (dp[ind][T] != -1) {
        return dp[ind][T];
    }
    int notTaken = 0 + minimumElementsUtil(arr, ind-1, T, dp);
    int taken = INT_MAX;
    if (arr[ind] <= T) {
        taken = 1 + minimumElementsUtil(arr, ind, T-arr[ind], dp);
    }
    return dp[ind][T] = (notTaken < taken) ? notTaken : taken;
}

int minimumElements(int arr[], int T, int n){
    int dp[n][T+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= T; j++){
            dp[i][j] = -1;
        }
    }
    int ans = minimumElementsUtil(arr, n-1, T, dp);
    if (ans >= INT_MAX) {
        return -1;
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3};
    int T = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("The minimum number of coins required to form the target sum is %d\n", minimumElements(arr, T, n));
    return 0;
}
