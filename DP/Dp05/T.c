#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solveUtil(int ind, int arr[], int dp[], int n){
    if(ind < 0)
        return 0;
    if(ind == 0)
        return arr[ind];
    if(dp[ind] != -1)
        return dp[ind];
    int pick = arr[ind] + solveUtil(ind-2, arr, dp, n);
    int nonPick = 0 + solveUtil(ind-1, arr, dp, n);
    return dp[ind] = (pick > nonPick) ? pick : nonPick;
}

int solve(int n, int arr[]){
    int dp[n];
    memset(dp, -1, sizeof(dp));
    return solveUtil(n-1, arr, dp, n);
}

int main(){
    int arr[] = {2,1,4,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", solve(n, arr));
    return 0;
}
