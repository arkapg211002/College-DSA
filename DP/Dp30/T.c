#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_M 1000

int lcs(char s1[], char s2[], int n, int m) {
    int dp[MAX_N+1][MAX_M+1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 0 + ((dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int canYouMake(char str1[], char str2[]) {
    int n = strlen(str1);
    int m = strlen(str2);
    
    int k = lcs(str1, str2, n, m);
    
    return (n-k)+(m-k);
}

int main(void) {
    char str1[] = "abcd";
    char str2[] = "anc";
    printf("The Minimum operations required to convert str1 to str2: %d\n", canYouMake(str1, str2));
    return 0;
}
