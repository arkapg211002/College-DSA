#include <stdio.h>
#include <limits.h>

int f(int arr[], int i, int j, int dp[][j+1]) {
    
    // base condition
    if (i == j)
        return 0;
        
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    // partitioning loop
    for (int k = i; k <= j-1; k++) {
        
        int ans = f(arr, i, k, dp) + f(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = (mini < ans) ? mini : ans;
    }
    
    dp[i][j] = mini;
    return mini;
}

int matrixMultiplication(int arr[], int N) {
    
    int dp[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (int i = 1; i < N; i++) {
        dp[i][i] = 0;
    }
    
    for (int i = N-1; i >= 1; i--) {
        for (int j = i+1; j < N; j++) {
            
            int mini = INT_MAX;
    
            // partitioning loop
            for (int k = i; k <= j-1; k++) {
                
                int ans = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                
                mini = (mini < ans) ? mini : ans;
            }
            
            dp[i][j] = mini;
        }
    }
    
    return dp[1][N-1];
}

int main() {
	
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("The minimum number of operations are %d\n", matrixMultiplication(arr, n));
	
    return 0;
}
