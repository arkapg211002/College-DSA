#include <stdio.h>

#define MAX_SIZE 100000

long solve(int n, int arr[]) {
    long prev = arr[0];
    long prev2 = 0;

    for (int i = 1; i < n; i++) {
        long pick = arr[i];
        if (i > 1) pick += prev2;
        long nonPick = 0 + prev;

        long cur_i = (pick > nonPick) ? pick : nonPick;
        prev2 = prev;
        prev = cur_i;
    }

    return prev;
}

long robStreet(int n, int arr[]) {
    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];

    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++) {
        if (i != 0)
            arr1[i - 1] = arr[i];
        if (i != n - 1)
            arr2[i] = arr[i];
    }

    long ans1 = solve(n - 1, arr1);
    long ans2 = solve(n - 1, arr2);

    return (ans1 > ans2) ? ans1 : ans2;
}

int main() {
    int arr[] = {1, 5, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%ld", robStreet(n, arr));

    return 0;
}
