#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int lcs(char s1[], char s2[], int n, int m) {
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + (dp[ind1-1][ind2] > dp[ind1][ind2-1] ? dp[ind1-1][ind2] : dp[ind1][ind2-1]);
        }
    }

    return dp[n][m];
}

void reverse_string(char str[]) {
    int length = strlen(str);
    char temp;
    for(int i=0; i<length/2; i++){
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

char* shortestSupersequence(char s1[], char s2[]) {
    int n = strlen(s1);
    int m = strlen(s2);
    int len = lcs(s1, s2, n, m);
    int i = n;
    int j = m;
    int index = len - 1;
    char ans[MAX_LENGTH] = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans[index] = s1[i - 1];
            index--;
            i--;
            j--;
        } else if (lcs(s1, s2, i - 1, j) > lcs(s1, s2, i, j - 1)) {
            ans[index] = s1[i - 1];
            index--;
            i--;
        } else {
            ans[index] = s2[j - 1];
            index--;
            j--;
        }
    }

    while(i > 0){
        ans[index] = s1[i-1];
        index--;
        i--;
    }

    while(j > 0){
        ans[index] = s2[j-1];
        index--;
        j--;
    }

    ans[len] = '\0';
    reverse_string(ans);

    return strdup(ans);
}

int main() {
    char s1[] = "brute";
    char s2[] = "groot";

    char* ans = shortestSupersequence(s1, s2);

    printf("The Shortest Common Supersequence is %s\n", ans);

    free(ans);

    return 0;
}
