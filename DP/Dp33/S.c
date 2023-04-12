#include <stdio.h>
#include <string.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int editDistance(char *S1, char *S2) {
    int n = strlen(S1);
    int m = strlen(S2);

    int prev[m+1];
    int cur[m+1];

    for(int j = 0; j <= m; j++){
        prev[j] = j;
    }

    for(int i = 1; i <= n; i++){
        cur[0] = i;
        for(int j = 1; j <= m; j++){
            if(S1[i-1] == S2[j-1])
                cur[j] = prev[j-1];
            else
                cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
        }
        memcpy(prev, cur, sizeof(prev));
    }

    return prev[m];
}

int main() {
    char s1[] = "horse";
    char s2[] = "ros";

    printf("The minimum number of operations required is: %d\n", editDistance(s1, s2));

    return 0;
}
