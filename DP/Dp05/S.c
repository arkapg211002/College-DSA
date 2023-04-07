
#include <stdio.h>

int solve(int n, int arr[]) {
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = (pick > nonPick) ? pick : nonPick;
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int main() {
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", solve(n, arr));
    return 0;
}
