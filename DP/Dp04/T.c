#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int solveUtil(int n, int* height, int* dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= (jump < mmSteps) ? jump : mmSteps;
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int solve(int n, int* height, int k){
    int* dp = (int*)malloc(n * sizeof(int));
    if(dp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        dp[i] = -1;
    }
    int result = solveUtil(n, height, dp, k);
    free(dp);
    return result;
}

int main(){
    int height[] = {30,10,60,10,60,50};
    int n = sizeof(height) / sizeof(height[0]);
    int k = 2;
    printf("%d\n", solve(n, height, k));
    return 0;
}
