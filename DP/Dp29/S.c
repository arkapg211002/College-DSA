#include <stdio.h>
#include <string.h>

int lcs(char s1[], char s2[], int n, int m) {
    int prev[m+1], cur[m+1];
    memset(prev, 0, sizeof(prev));
    memset(cur, 0, sizeof(cur));
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1; ind1<=n; ind1++) {
        for(int ind2=1; ind2<=m; ind2++) {
            if(s1[ind1-1] == s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + (prev[ind2] > cur[ind2-1] ? prev[ind2] : cur[ind2-1]);
        }
        
        memcpy(prev, cur, sizeof(cur));
    }
    
    return prev[m];
}

int longestPalindromeSubsequence(char s[], int n) {
    char t[n+1];
    strcpy(t, s);
    strrev(t);
    return lcs(t, s, n, n);
}

int minInsertion(char s[], int n) {
    int k = longestPalindromeSubsequence(s, n);
    return n - k;
}

int main() {
    char s[] = "abcaa";
    int n = strlen(s);
    printf("The Minimum insertions required to make string palindrome: %d\n", minInsertion(s, n));
    return 0;
}
