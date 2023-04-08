#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_M 50

int maximumChocolates(int n, int m, int grid[MAX_M][MAX_M]) {
  int front[MAX_M][MAX_M];
  int cur[MAX_M][MAX_M];
  int j1, j2, i, di, dj, ans, maxi;

  for (j1 = 0; j1 < m; j1++) {
    for (j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  for (i = n - 2; i >= 0; i--) {
    for (j1 = 0; j1 < m; j1++) {
      for (j2 = 0; j2 < m; j2++) {
        maxi = INT_MIN;

        for (di = -1; di <= 1; di++) {
          for (dj = -1; dj <= 1; dj++) {
            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
              ans += (int) pow(-10, 9);
            else
              ans += front[j1 + di][j2 + dj];

            maxi = (ans > maxi) ? ans : maxi;
          }
        }
        cur[j1][j2] = maxi;
      }
    }

    for (j1 = 0; j1 < m; j1++) {
      for (j2 = 0; j2 < m; j2++) {
        front[j1][j2] = cur[j1][j2];
      }
    }
  }

  return front[0][m - 1];
}

int main() {
  int matrix[3][4] = {{2,3,1,2},
                      {3,4,2,2},
                      {5,6,3,5}};

  int n = 3;
  int m = 4;

  printf("%d\n", maximumChocolates(n, m, matrix));

  return 0;
}
