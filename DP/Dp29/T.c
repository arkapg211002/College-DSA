#include <stdio.h>
#include <string.h>

int lcs(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int dp[n + 1][m + 1];
    int i, j;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 0 + ((dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]);
            }
        }
    }
    
    return dp[n][m];
}

int longestPalindromeSubsequence(char *s) {
    char t[strlen(s)];
    strcpy(t, s);
    strrev(t);
    return lcs(t, s);
}

int minInsertion(char *s) {
    int n = strlen(s);
    int k = longestPalindromeSubsequence(s);
    return n - k;
}

int main() {
    char s[] = "abcaa";
    printf("The Minimum insertions required to make string palindrome: %d\n", minInsertion(s));
    return 0;
}
