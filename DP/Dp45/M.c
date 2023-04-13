#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int compare(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    if (n1 != n2 + 1)
        return 0;

    int first = 0;
    int second = 0;

    while (first < n1) {
        if (second < n2 && s1[first] == s2[second]) {
            first++;
            second++;
        }
        else
            first++;
    }
    return (first == n1 && second == n2);
}

int comp(const void* s1, const void* s2) {
    char* str1 = *(char**) s1;
    char* str2 = *(char**) s2;
    return strlen(str1) - strlen(str2);
}

int longestStrChain(char** arr, int n) {
    qsort(arr, n, sizeof(char*), comp);
    int* dp = (int*) calloc(n, sizeof(int));
    int maxi = 1;

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
            }
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    free(dp);
    return maxi;
}

int main() {

    char* words[] = {"a", "b", "ba", "bca", "bda", "bdca"};
    int n = sizeof(words) / sizeof(words[0]);
    printf("The length of the longest string chain is: %d\n", longestStrChain(words, n));

    return 0;
}
