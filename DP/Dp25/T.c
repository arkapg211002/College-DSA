#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int lcs(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int dp[MAX_N + 1][MAX_N + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + (dp[ind1 - 1][ind2] > dp[ind1][ind2 - 1] ? dp[ind1 - 1][ind2] : dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

int main() {
    char s1[] = "acd";
    char s2[] = "ced";

    printf("The Length of Longest Common Subsequence is %d\n", lcs(s1, s2));

    return 0;
}
