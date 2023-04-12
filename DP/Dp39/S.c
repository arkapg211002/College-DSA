#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 100005

int max(int a, int b) {
    return (a > b) ? a : b;
}

int stockProfit(int Arr[], int n)
{  
    int cur[2] = {0};
    int front1[2] = {0};
    int front2[2] = {0};
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit=0;
            
            if(buy==0){// We can buy the stock
                profit = max(0+front1[0], -Arr[ind] + front1[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        for(int i=0; i<2; i++) {
            front2[i] = front1[i];
            front1[i] = cur[i];
        }
    }
    
    return cur[0];
}

int main()
{
    int prices[]= {4,9,0,4,10};
    int n = sizeof(prices)/sizeof(prices[0]);

    printf("The maximum profit that can be generated is %d\n", stockProfit(prices, n));

    return 0;
}
