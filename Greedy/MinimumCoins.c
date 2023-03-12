#include <stdio.h>

int main() {
    int coins[] = {25, 10, 5, 1}; // coin denominations
    int num_coins = 4; // number of different coin denominations
    int amount = 67; // amount to make change for
    int count = 0; // count of coins used
    
    // iterate through each coin denomination
    for (int i = 0; i < num_coins; i++) {
        // use as many coins of this denomination as possible
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    
    // output the result
    printf("Minimum number of coins required: %d\n", count);
    
    return 0;
}

