#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minimumElements(int arr[], int n, int T){
    
    int dp[n][T+1];
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = (int)pow(10,9);
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = (int)pow(10,9);
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = fmin(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=(int)pow(10,9)) return -1;
    return ans;
}

int main(void) {
    
    int arr[] ={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int T=7;
                                 
    printf("The minimum number of coins required to form the target sum is %d\n", minimumElements(arr, n, T));

    return 0;
}
