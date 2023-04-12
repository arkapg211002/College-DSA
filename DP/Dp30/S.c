#include <stdio.h>
#include <string.h>

int lcs(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int prev[m + 1];
    int cur[m + 1];
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1 = 1; ind1 <= n; ind1++){
        for(int ind2 = 1; ind2 <= m; ind2++){
            if(s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = 0 + (prev[ind2] > cur[ind2 - 1] ? prev[ind2] : cur[ind2 - 1]);
        }
        memcpy(prev, cur, sizeof(cur));
    }
    
    return prev[m];
}

int canYouMake(char* str1, char* str2){
    int n = strlen(str1);
    int m = strlen(str2);
    
    int k = lcs(str1, str2);
    
    return (n - k) + (m - k);
}

int main(void) {
    char str1[] = "abcd";
    char str2[] = "anc";
    printf("The Minimum operations required to convert str1 to str2: %d", canYouMake(str1, str2));
    return 0;
}
