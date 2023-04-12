#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

bool isAllStars(char S1[], int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

bool wildcardMatching(char S1[], char S2[]) {
    int n = strlen(S1);
    int m = strlen(S2);

    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = isAllStars(S1, i - 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else {
                if (S1[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

int main() {
    char S1[MAX], S2[MAX];

    strcpy(S1, "ab*cd");
    strcpy(S2, "abdefcd");

    if (wildcardMatching(S1, S2))
        printf("String S1 and S2 do match\n");
    else
        printf("String S1 and S2 do not match\n");

    return 0;
}
