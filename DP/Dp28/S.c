#include <stdio.h>
#include <string.h>

int lcs(char *s1, char *s2) {
    
    int n=strlen(s1);
    int m=strlen(s2);

    int prev[m+1];
    int cur[m+1];
    memset(prev, 0, sizeof(prev));
    memset(cur, 0, sizeof(cur));

    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + (prev[ind2] > cur[ind2-1] ? prev[ind2] : cur[ind2-1]);
        }
        memcpy(prev, cur, sizeof(cur));
    }
    
    return prev[m];
}

int longestPalindromeSubsequence(char *s){
    char *t = s;
    int n = strlen(s);
    char ss[n+1];
    int i = 0;
    while (n > 0) {
        ss[i++] = s[n-1];
        n--;
    }
    ss[i] = '\0';
    return lcs(ss,t);
}

int main() {

    char s[]= "bbabcbcab";
                                 
    printf("The Length of Longest Palindromic Subsequence is %d\n", longestPalindromeSubsequence(s));
    return 0;
}
