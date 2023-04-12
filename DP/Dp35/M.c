#include <stdio.h>

int maximumProfit(int Arr[], int n) {
    int maxProfit = 0;
    int mini = Arr[0];
	
    for (int i = 1; i < n; i++) {
        int curProfit = Arr[i] - mini;
        maxProfit = (curProfit > maxProfit) ? curProfit : maxProfit;
        mini = (Arr[i] < mini) ? Arr[i] : mini;
    }
	
    return maxProfit;
}

int main() {
    int Arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(Arr) / sizeof(Arr[0]);
	
    printf("The maximum profit by selling the stock is %d\n", maximumProfit(Arr, n));
	
    return 0;
}
