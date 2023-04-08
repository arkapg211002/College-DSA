#include <stdio.h>

int minimumPathSum(int triangle[][4], int n) {
    int front[4], cur[4];

    for(int j = 0; j < n; j++) {
        front[j] = triangle[n-1][j];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];
            cur[j] = (down < diagonal) ? down : diagonal;
        }
        for(int j = 0; j <= i; j++) {
            front[j] = cur[j];
        }
    }

    return front[0];
}

int main() {
    int triangle[][4] = {{1},
                         {2,3},
                         {3,6,7},
                         {8,9,6,10}};

    int n = 4;

    printf("%d\n", minimumPathSum(triangle, n));

    return 0;
}
