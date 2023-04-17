#include <stdio.h>
#include <limits.h>

int f(int arr[], int i, int j) {
    // base condition
    if (i == j)
        return 0;

    int k, ans, mini = INT_MAX;
    // partitioning loop
    for (k = i; k <= j - 1; k++) {
        ans = f(arr, i, k) + f(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mini = (ans < mini) ? ans : mini;
    }
    return mini;
}

int matrixMultiplication(int arr[], int N) {
    int i = 1, j = N - 1;
    return f(arr, i, j);
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The minimum number of operations are %d\n", matrixMultiplication(arr, n));

    return 0;
}
