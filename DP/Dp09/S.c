#include <stdio.h>

int countWays(int m, int n) {
    int prev[n];
    int i, j, up, left, temp[n];

    for (i = 0; i < n; i++) {
        prev[i] = 0;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

            up = 0;
            left = 0;

            if (i > 0) {
                up = prev[j];
            }
            if (j > 0) {
                left = temp[j-1];
            }

            temp[j] = up + left;
        }

        for (j = 0; j < n; j++) {
            prev[j] = temp[j];
        }
    }

    return prev[n-1];
}

int main() {
    int m = 3;
    int n = 2;

    printf("%d\n", countWays(m, n));

    return 0;
}
