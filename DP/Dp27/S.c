#include <stdio.h>
#include <string.h>

int lcs(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int prev[m + 1];
    int cur[m + 1];

    int ans = 0;

    for (int i = 0; i <= m; i++) {
        prev[i] = 0;
        cur[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                int val = 1 + prev[j - 1];
                cur[j] = val;
                ans = (ans > val) ? ans : val;
            } else {
                cur[j] = 0;
            }
        }
        memcpy(prev, cur, sizeof(cur));
    }

    return ans;
}

int main() {
    char s1[] = "abcjklp";
    char s2[] = "acjkp";

    printf("The Length of Longest Common Substring is %d\n", lcs(s1, s2));

    return 0;
}
