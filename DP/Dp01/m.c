#include <stdio.h>
#include <stdlib.h>

int f(int n, int* dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}

int main(){
    int n = 5;
    int *dp = (int*) malloc((n+1) * sizeof(int));
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    printf("%d\n", f(n, dp));
    free(dp);
    return 0;
}

