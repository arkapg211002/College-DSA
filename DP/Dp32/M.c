#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1001
#define PRIME 1000000007

int countUtil(char s1[], char s2[], int ind1, int ind2, int dp[MAX][MAX]){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1]==s2[ind2]){
        int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (leaveOne + stay)%PRIME;
    }
    
    else{
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
    }
}

int subsequenceCounting(char t[], char s[], int lt, int ls) {
    int dp[MAX][MAX];
    memset(dp, -1, sizeof(dp));
    return countUtil(t, s, lt-1, ls-1, dp);
} 

int main() {

  char s1[] = "babgbag";
  char s2[] = "bag";
  int lt = strlen(s1);
  int ls = strlen(s2);

  printf("The Count of Distinct Subsequences is %d\n", subsequenceCounting(s1, s2, lt, ls));
  return 0;
}
