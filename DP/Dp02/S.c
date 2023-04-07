#include <stdio.h>

int main() {
  int n = 3;
  int dp[4] = {-1, 1, 1, -1};
  
  dp[0] = 1;
  
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  
  printf("%d", dp[n]);
  return 0;
}
