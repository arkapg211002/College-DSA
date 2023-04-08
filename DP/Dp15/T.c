#include <stdio.h>
#include <stdbool.h>

bool subsetSumToK(int n, int k, int arr[]) {
    bool prev[k + 1];
    int i, ind, target;
    
    for (i = 0; i <= k; i++) {
        prev[i] = false;
    }
    
    prev[0] = true;
    
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }
    
    for (ind = 1; ind < n; ind++) {
        bool cur[k + 1];
        
        for (i = 0; i <= k; i++) {
            cur[i] = false;
        }
        
        cur[0] = true;
        
        for (target = 1; target <= k; target++) {
            bool notTaken = prev[target];
            bool taken = false;
            
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }
            
            cur[target] = notTaken || taken;
        }
        
        for (i = 0; i <= k; i++) {
            prev[i] = cur[i];
        }
    }
    
    return prev[k];
}

bool canPartition(int n, int arr[]) {
    int totSum = 0;
    int i, j;
    
    for (i = 0; i < n; i++) {
        totSum += arr[i];
    }
    
    if (totSum % 2 == 1) {
        return false;
    } else {
        int k = totSum / 2;
        bool dp[n][k + 1];
        
        for (i = 0; i < n; i++) {
            for (j = 0; j <= k; j++) {
                dp[i][j] = false;
            }
        }
        
        for (i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }
        
        for (i = 1; i < n; i++) {
            for (j = 1; j <= k; j++) {
                bool notTaken = dp[i - 1][j];
                bool taken = false;
                
                if (arr[i] <= j) {
                    taken = dp[i - 1][j - arr[i]];
                }
                
                dp[i][j] = notTaken || taken;
            }
        }
        
        return dp[n - 1][k];
    }
}

int main() {
    int arr[] = {2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (canPartition(n, arr)) {
        printf("The Array can be partitioned into two equal subsets\n");
    } else {
        printf("The Array cannot be partitioned into two equal subsets\n");
    }
    
    return 0;
}
