#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100
#define MAX_M 100

int max(int a, int b) {
  return a > b ? a : b;
}

int maximumChocolates(int n, int m, int grid[MAX_N][MAX_M]) {
  int dp[MAX_N][MAX_M][MAX_M];

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
        int maxi = -2147483647; // equivalent to Integer.MIN_VALUE in Java

        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            int ans;
            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
              ans += (int)pow(-10, 9);
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }

        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
}

int main() {
  int matrix[MAX_N][MAX_M] = {{2,3,1,2},
                              {3,4,2,2},
                              {5,6,3,5}};
  int n = 3;
  int m = 4;

  printf("%d\n", maximumChocolates(n, m, matrix));
  return 0;
}
