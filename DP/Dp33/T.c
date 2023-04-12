#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

int editDistance(char* S1, char* S2) {
    int n = strlen(S1);
    int m = strlen(S2);

    int dp[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = 0 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + (dp[i - 1][j - 1] < dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j]);
                dp[i][j] = dp[i][j] < dp[i][j - 1] ? dp[i][j] : dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}

int main() {
    char s1[] = "horse";
    char s2[] = "ros";

    printf("The minimum number of operations required is: %d\n", editDistance(s1, s2));
    
    return 0;
}
