#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfit(int Arr[], int n) {
    // Creating a 3d - dp of size [n+1][2][3] initialized to 0
    int dp[MAXN+1][2][3] = {0};
                                            
    // As dp array is intialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -Arr[ind] + dp[ind+1][1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                Arr[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    
    
    return dp[0][0][2];
   
}

int main() {

    int prices[] = {3,3,5,0,0,3,1,4};
    int n = sizeof(prices) / sizeof(prices[0]);
                                 
    printf("The maximum profit that can be generated is %d", maxProfit(prices, n));

    return 0;
}
