#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int isAllStars(char S1[], int i) {
  for (int j = 0; j <= i; j++) {
    if (S1[j] != '*')
      return 0;
  }
  return 1;
}

int wildcardMatchingUtil(char S1[], char S2[], int i, int j, int dp[MAX_N][MAX_N]) {
  // Base Conditions
  if (i < 0 && j < 0)
    return 1;
  if (i < 0 && j >= 0)
    return 0;
  if (j < 0 && i >= 0)
    return isAllStars(S1, i) ? 1 : 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (S1[i] == S2[j] || S1[i] == '?')
    return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
  else {
    if (S1[i] == '*')
      return (wildcardMatchingUtil(S1, S2, i - 1, j, dp) == 1 || wildcardMatchingUtil(S1, S2, i, j - 1, dp) == 1) ? 1 : 0;
    else
      return 0;
  }
}

int wildcardMatching(char S1[], char S2[]) {
  int n = strlen(S1);
  int m = strlen(S2);

  int dp[MAX_N][MAX_N];
  memset(dp, -1, sizeof(dp));

  return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}

int main() {
  char S1[] = "ab*cd";
  char S2[] = "abdefcd";

  if (wildcardMatching(S1, S2) == 1)
    printf("String S1 and S2 do match\n");
  else
    printf("String S1 and S2 do not match\n");

  return 0;
}
