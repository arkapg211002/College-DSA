#include <stdio.h>
#include <stdlib.h>

long getMaximumProfit(long Arr[], int n)
{
    long ahead[2], cur[2], profit;
    
    // base condition
    ahead[0] = ahead[1] = 0;
    
    for (int ind = n-1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = (0 + ahead[0]) > (-Arr[ind] + ahead[1]) ? (0 + ahead[0]) : (-Arr[ind] + ahead[1]);
            }
            if (buy == 1) { // We can sell the stock
                profit = (0 + ahead[1]) > (Arr[ind] + ahead[0]) ? (0 + ahead[1]) : (Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead[0] = cur[0];
        ahead[1] = cur[1];
    }
    return cur[0];
}

int main()
{
    int n = 6;
    long Arr[] = {7, 1, 5, 3, 6, 4};
    
    printf("The maximum profit that can be generated is %ld\n", getMaximumProfit(Arr, n));
    
    return 0;
}
