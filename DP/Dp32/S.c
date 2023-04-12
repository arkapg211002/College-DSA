#include <stdio.h>
#include <string.h>
#include <math.h>

#define prime 1000000007

int subsequenceCounting(char* s1, char* s2, int n, int m) {
    int prev[m+1];
    memset(prev, 0, sizeof(prev));
    prev[0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            if(s1[i-1] == s2[j-1]){
                prev[j] = (prev[j-1] + prev[j]) % prime;
            }
            else{
                prev[j] = prev[j];
            }
        }
    }
    
    return prev[m];
}

int main(void) {
    char s1[] = "babgbag";
    char s2[] = "bag";

    printf("The Count of Distinct Subsequences is %d\n", subsequenceCounting(s1, s2, strlen(s1), strlen(s2)));
    return 0;
}
