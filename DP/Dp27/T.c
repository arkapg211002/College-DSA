#include <stdio.h>
#include <string.h>

int lcs(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int dp[n + 1][m + 1];
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                int val = 1 + dp[i - 1][j - 1];
                dp[i][j] = val;
                ans = (ans > val) ? ans : val;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    char s1[] = "abcjklp";
    char s2[] = "acjkp";

    printf("The Length of Longest Common Substring is %d\n", lcs(s1, s2));
    
    return 0;
}
