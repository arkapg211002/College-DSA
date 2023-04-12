#include <stdio.h>
#include <stdlib.h>

long maximumProfit(int n, int fee, int Arr[]) {
    if(n==0) return 0;

    long *ahead = calloc(2, sizeof(long));
    long *cur = calloc(2, sizeof(long));

    // base condition
    ahead[0] = ahead[1] = 0;

    long profit=0;

    for(int ind=n-1; ind>=0; ind--) {
        for(int buy=0; buy<=1; buy++) {
            if(buy==0) { // We can buy the stock
                profit = 0 + ahead[0];
                if (-Arr[ind] + ahead[1] > profit) {
                    profit = -Arr[ind] + ahead[1];
                }
            }
            if(buy==1) { // We can sell the stock
                profit = 0 + ahead[1];
                if (Arr[ind] - fee + ahead[0] > profit) {
                    profit = Arr[ind] - fee + ahead[0];
                }
            }
            cur[buy] = profit;
        }

        // copy cur to ahead
        ahead[0] = cur[0];
        ahead[1] = cur[1];
    }

    long result = cur[0];
    free(ahead);
    free(cur);

    return result;
}

int main(void) {
    int prices[] = {1,3,2,8,4,9};
    int n = sizeof(prices)/sizeof(prices[0]);
    int fee = 2;

    printf("The maximum profit that can be generated is %ld\n", maximumProfit(n, fee, prices));
    return 0;
}
