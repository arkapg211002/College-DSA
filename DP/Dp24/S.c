#include <stdio.h>
#include <limits.h>

int cutRodUtil(int price[], int ind, int N, int dp[][N + 1]){
    if(ind == 0){
        return N * price[0];
    }
    
    if(dp[ind][N] != -1)
        return dp[ind][N];
        
    int notTaken = 0 + cutRodUtil(price, ind - 1, N, dp);
    
    int taken = INT_MIN;
    int rodLength = ind + 1;
    if(rodLength <= N)
        taken = price[ind] + cutRodUtil(price, ind, N - rodLength, dp);
        
    return dp[ind][N] = (notTaken > taken) ? notTaken : taken;
}

int cutRod(int price[], int N) {
    int cur[N + 1];
    int dp[N][N + 1];
    
    for(int i = 0; i <= N; i++){
        cur[i] = i * price[0];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++){
            dp[i][j] = -1;
        }
    }
    
    for(int ind = 1; ind < N; ind++){
        for(int length = 0; length <= N; length++){
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind + 1;
             if(rodLength <= length)
                taken = price[ind] + cur[length - rodLength];
        
             cur[length] = (notTaken > taken) ? notTaken : taken;   
        }
    }
    
    return cur[N];
}

int main() {
    int price[] = {2, 5, 7, 8, 10};
    int n = sizeof(price) / sizeof(price[0]);
    
    printf("The Maximum price generated is %d", cutRod(price, n));
    
    return 0;
}
