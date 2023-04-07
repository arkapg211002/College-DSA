#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 100

int f(int day, int last, int points[][3], int dp[][4])
{
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                maxi = (points[0][i] > maxi) ? points[0][i] : maxi;
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            int activity = points[day][i] + f(day - 1, i, points, dp);
            maxi = (activity > maxi) ? activity : maxi;
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, int points[][3])
{
    int dp[MAX_DAYS][4];
    for (int i = 0; i < MAX_DAYS; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = -1;
        }
    }

    return f(n - 1, 3, points, dp);
}

int main()
{
    int points[][3] = {{10, 40, 70},
                       {20, 50, 80},
                       {30, 60, 90}};

    int n = sizeof(points) / sizeof(points[0]);
    printf("%d\n", ninjaTraining(n, points));

    return 0;
}
