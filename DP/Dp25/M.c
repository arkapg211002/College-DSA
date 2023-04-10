#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int lcsUtil(char *s1, char *s2, int ind1, int ind2, int dp[MAX_N][MAX_N]) {
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = 0 + (lcsUtil(s1, s2, ind1, ind2 - 1, dp) > lcsUtil(s1, s2, ind1 - 1, ind2, dp) ? lcsUtil(s1, s2, ind1, ind2 - 1, dp) : lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

int lcs(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int dp[MAX_N][MAX_N];
    memset(dp, -1, sizeof(dp));

    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}

int main() {
    char s1[] = "acd";
    char s2[] = "ced";

    printf("The Length of Longest Common Subsequence is %d\n", lcs(s1, s2));

    return 0;
}
