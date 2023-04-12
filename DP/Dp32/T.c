#include <stdio.h>
#include <string.h>
#include <math.h>

#define prime (int)(pow(10,9)+7)

int subsequenceCounting(char* s1, char* s2, int n, int m) {
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % prime;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    char s1[] = "babgbag";
    char s2[] = "bag";
    int n = strlen(s1);
    int m = strlen(s2);

    printf("The Count of Distinct Subsequences is %d\n", subsequenceCounting(s1, s2, n, m));

    return 0;
}
