#include <stdio.h>

int countWays(int m, int n) {
    int prev[n];
    int i, j;
    for (i = 0; i < m; i++) {
        int temp[n];
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }
        for (j = 0; j < n; j++) {
            prev[j] = temp[j];
        }
    }
    return prev[n - 1];
}

int main() {
    int m = 3;
    int n = 2;
    printf("%d", countWays(m, n));
    return 0;
}
