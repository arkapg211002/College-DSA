#include <stdio.h>

#define MAXN 100
#define MAXT 10000

int n, target;
int arr[MAXN];
long long dp[MAXN][MAXT+1];

long long countWaysToMakeChangeUtil(int ind, int T){
    if(ind == 0){
        if(T%arr[0]==0)
            return 1;
        else
            return 0;
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    long long notTaken = countWaysToMakeChangeUtil(ind-1, T);
    
    long long taken = 0;
    if(arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(ind, T-arr[ind]);
        
    return dp[ind][T] = notTaken + taken;
}

long long countWaysToMakeChange(int n, int T){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=T;j++){
            dp[i][j]=-1;
        }
    }
    return countWaysToMakeChangeUtil(n-1, T);
}

int main(){
    n = 3;
    target = 4;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
                     
    printf("The total number of ways is %lld\n", countWaysToMakeChange(n, target));

    return 0;
}
