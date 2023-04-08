#include <stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int cutRodUtil(int price[], int ind, int N, int dp[][N+1]) {
    if (ind == 0) {
        return N*price[0];
    }

    if (dp[ind][N] != -1) {
        return dp[ind][N];
    }

    int notTaken = 0 + cutRodUtil(price, ind-1, N, dp);

    int taken = -1e9;
    int rodLength = ind+1;
    if (rodLength <= N) {
        taken = price[ind] + cutRodUtil(price, ind, N-rodLength, dp);
    }

    return dp[ind][N] = max(notTaken, taken);
}

int cutRod(int price[], int N) {
    int dp[N][N+1];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = -1;
        }
    }

    return cutRodUtil(price, N-1, N, dp);
}

int main() {
    int price[] = {2, 5, 7, 8, 10};
    int n = sizeof(price) / sizeof(price[0]);

    printf("The Maximum price generated is %d\n", cutRod(price, n));
    return 0;
}
