#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int arr[MAX_N];
int dp[MAX_N];
int hash[MAX_N];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int lower_bound(int *arr, int n, int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int* divisibleSet(int *arr, int n, int *resultSize) {

    // sort the array
    qsort(arr, n, sizeof(int), (const void*)cmp);

    int i, j, ans = -1, lastIndex = -1;
    for (i = 0; i < n; i++) {
        dp[i] = 1;
        hash[i] = i;
        for (j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    int *temp = (int*)malloc(ans * sizeof(int));
    for (i = ans - 1; i >= 0; i--) {
        temp[i] = arr[lastIndex];
        lastIndex = hash[lastIndex];
    }

    *resultSize = ans;
    return temp;
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int arr[] = {1, 16, 7, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int resultSize;
    int *ans = divisibleSet(arr, n, &resultSize);

    printf("The longest divisible subset elements are: ");
    int i;
    for (i = 0; i < resultSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);
    return 0;
}
