#include <stdio.h>
#include <string.h>

#define MAXN 1000

int next[MAXN + 1], cur[MAXN + 1];

int longestIncreasingSubsequence(int arr[], int n) {
    int i, j;

    for (i = n - 1; i >= 0; i--) {
        for (j = i - 1; j >= -1; j--) {
            int notTake = 0 + next[j + 1];

            int take = 0;

            if (j == -1 || arr[i] > arr[j]) {
                take = 1 + next[i + 1];
            }

            cur[j + 1] = (notTake > take ? notTake : take);
        }

        memcpy(next, cur, sizeof(int) * (n + 1));
    }

    return cur[0];
}

int main(void) {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The length of the longest increasing subsequence is %d\n", longestIncreasingSubsequence(arr, n));

    return 0;
}
