#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int dp[MAX_LEN + 1][MAX_LEN + 1];

int lcs(char* s1, char* s2, int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 0 + ((dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int longestPalindromeSubsequence(char* s, int n) {
    char t[MAX_LEN + 1];
    for (int i = 0; i < n; i++) {
        t[i] = s[n - i - 1];
    }
    t[n] = '\0';
    return lcs(t, s, n, n);
}

int main() {
    char s[] = "bbabcbcab";
    int n = strlen(s);
    
    printf("The Length of Longest Palindromic Subsequence is %d\n", longestPalindromeSubsequence(s, n));

    return 0;
}
