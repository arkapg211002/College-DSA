#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int solve(int ind, int* height, int* dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne = solve(ind-1, height, dp) + abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height, dp) + abs(height[ind]-height[ind-2]);

    return dp[ind] = jumpOne < jumpTwo ? jumpOne : jumpTwo;
}

int main(){
    int height[] = {30,10,60,10,60,50};
    int n = sizeof(height) / sizeof(height[0]);
    int *dp = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        dp[i] = -1;
    }
    printf("%d\n", solve(n-1, height, dp));
    free(dp);
    return 0;
}
