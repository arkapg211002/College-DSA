#include <stdio.h>
#include <stdlib.h>

int findWaysUtil(int ind, int target, int arr[], int dp[][target+1]){
    if(target==0)
        return 1;
    
    if(ind == 0)
        return arr[0] == target?1:0;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1, target, arr, dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1, target-arr[ind], arr, dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(int num[], int k, int n){
    int dp[n][k+1];
    for(int i=0; i<n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j] = -1;
    
    return findWaysUtil(n-1, k, num, dp);
}

int main() {

  int arr[] = {1,2,2,3};
  int k=3;
  int n = sizeof(arr)/sizeof(arr[0]);
                                 
  printf("The number of subsets found are %d\n", findWays(arr,k,n));
  
  return 0;
}
