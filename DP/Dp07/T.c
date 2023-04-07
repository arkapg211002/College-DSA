#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

int ninjaTraining(int n, int points[n][3]) {
    int dp[n][4];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != last) {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int main(void) {
    int points[][3] = {{10,40,70}, {20,50,80}, {30,60,90}};
    int n = sizeof(points) / sizeof(points[0]);
    printf("%d\n", ninjaTraining(n, points));
    return 0;
}
