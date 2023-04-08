#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int cutRod(int price[], int N) {
    int dp[N][N+1];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = -1;
        }
    }
    
    for(int i = 0; i <= N; i++) {
        dp[0][i] = i * price[0];
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            int notTaken = dp[i-1][j];
            int taken = -1;
            int rodLength = i + 1;
            if(rodLength <= j) {
                taken = price[i] + dp[i][j - rodLength];
            }
            dp[i][j] = max(notTaken, taken);
        }
    }
    
    return dp[N-1][N];
}

int main() {
    int price[] = {2, 5, 7, 8, 10};
    int n = sizeof(price) / sizeof(price[0]);
    printf("The Maximum price generated is %d\n", cutRod(price, n));
    return 0;
}
