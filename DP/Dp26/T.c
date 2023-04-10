#include <stdio.h>
#include <string.h>

void lcs(char* s1, char* s2) {

    int n = strlen(s1);
    int m = strlen(s2);

    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<=m; i++){
        dp[0][i] = 0;
    }

    for(int ind1=1; ind1<=n; ind1++){
        for(int ind2=1; ind2<=m; ind2++){
            if(s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + (dp[ind1-1][ind2] > dp[ind1][ind2-1] ? dp[ind1-1][ind2] : dp[ind1][ind2-1]);
        }
    }

    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len-1;
    char str[len+1];
    for(int k=1; k<=len; k++){
        str[k-1] = '$'; // dummy character
    }
    str[len] = '\0';
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            str[index] = s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(s1[i-1] > s2[j-1]){
            i--;
        }
        else j--;
    }
    printf("%s", str);
}

int main() {

    char s1[] = "abcde";
    char s2[] = "bdgek";

    printf("The Longest Common Subsequence is ");
    lcs(s1, s2);

    return 0;
}
