#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int getMaxPathSum(int n, int m, int matrix[][MAX_M]) {
    int prev[MAX_M], cur[MAX_M];

    // Initializing first row - base condition
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += prev[j - 1];
            } else {
                leftDiagonal += -1000000000;
            }

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += prev[j + 1];
            } else {
                rightDiagonal += -1000000000;
            }

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }

        // Swap the cur and prev arrays
        for (int j = 0; j < m; j++) {
            prev[j] = cur[j];
        }
    }

    int maxi = -1000000000;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
}

int main() {
    int matrix[MAX_N][MAX_M] = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    int n = 4, m = 4;
    printf("%d\n", getMaxPathSum(n, m, matrix));
    return 0;
}
