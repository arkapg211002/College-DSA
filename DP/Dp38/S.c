#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int *Arr, int n, int k)
{
    int ahead[2][k+1];
    int cur[2][k+1];

    int i, j, l;

    for(i = 0; i <= k; i++) {
        ahead[0][i] = 0;
        ahead[1][i] = 0;
    }

    for(i = n - 1; i >= 0; i--) {
        for(j = 0; j <= 1; j++) {
            for(l = 1; l <= k; l++) {
                if(j == 0) {
                    cur[j][l] = max(0 + ahead[0][l],
                                    -Arr[i] + ahead[1][l]);
                }
                else {
                    cur[j][l] = max(0 + ahead[1][l],
                                    Arr[i] + ahead[0][l-1]);
                }
            }
        }
        for(j = 0; j <= 1; j++) {
            for(l = 1; l <= k; l++) {
                ahead[j][l] = cur[j][l];
            }
        }
    }

    return ahead[0][k];

}

int main() {

    int prices[] = {3,3,5,0,0,3,1,4};
    int n = sizeof(prices) / sizeof(prices[0]);
    int k = 2;
                                 
    printf("The maximum profit that can be generated is %d", maxProfit(prices, n, k));

    return 0;
}
