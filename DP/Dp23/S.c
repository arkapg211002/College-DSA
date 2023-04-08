#include <stdio.h>

int unboundedKnapsack(int n, int W, int val[], int wt[]) {
    int cur[W+1];
    int i, j;

    // Base Condition
    for (i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0];
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j <= W; j++) {
            int notTaken = cur[j];
            int taken = -1;
            if (wt[i] <= j) {
                taken = val[i] + cur[j - wt[i]];
            }

            cur[j] = notTaken > taken ? notTaken : taken;
        }
    }

    return cur[W];
}

int main() {
    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int W = 10;
    int n = sizeof(wt) / sizeof(wt[0]);

    printf("The Maximum value of items, thief can steal is %d\n", unboundedKnapsack(n, W, val, wt));

    return 0;
}
