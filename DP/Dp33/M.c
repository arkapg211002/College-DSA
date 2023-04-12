#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1005
#define prime 1000000007

int editDistanceUtil(char* S1, char* S2, int i, int j, int dp[][MAX]) {
    if(i < 0)
        return j + 1;
    if(j < 0)
        return i + 1;
        
    if(dp[i][j] != -1) 
        return dp[i][j];
        
    if(S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);
        
    else 
        return dp[i][j] = 1 + fmin(editDistanceUtil(S1, S2, i - 1, j - 1, dp), 
                                fmin(editDistanceUtil(S1, S2, i - 1, j, dp), 
                                     editDistanceUtil(S1, S2, i, j - 1, dp)));
}

int editDistance(char* S1, char* S2) {
    int n = strlen(S1);
    int m = strlen(S2);
    
    int dp[MAX][MAX];
    memset(dp, -1, sizeof(dp));
    return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
}

int main() {
    char s1[] = "horse";
    char s2[] = "ros";

    printf("The minimum number of operations required is: %d\n", editDistance(s1, s2));
    return 0;
}
