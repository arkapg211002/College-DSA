#include <stdio.h>
#include <stdlib.h>

int mazeObstaclesUtil(int i, int j, int** maze, int** dp, int n, int m) {
    if(i>0 && j>0 && maze[i][j]==-1) return 0; 
    if(i==0 && j == 0)
        return 1;
    if(i<0 || j<0 || i>=n || j>=m)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = mazeObstaclesUtil(i-1,j,maze,dp,n,m);
    int left = mazeObstaclesUtil(i,j-1,maze,dp,n,m);

    return dp[i][j] = up+left;
}

int mazeObstacles(int n, int m, int** maze){
    int** dp = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        dp[i] = (int*)malloc(m * sizeof(int));
        for(int j=0; j<m; j++){
            dp[i][j] = -1;
        }
    }

    int result = mazeObstaclesUtil(n-1,m-1,maze,dp,n,m);

    for(int i=0; i<n; i++){
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {

    int maze[3][3] = {{0,0,0},
                      {0,-1,0},
                      {0,0,0}};

    int n = sizeof(maze)/sizeof(maze[0]);
    int m = sizeof(maze[0])/sizeof(int);

    int** mazePtr = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        mazePtr[i] = (int*)malloc(m * sizeof(int));
        for(int j=0; j<m; j++){
            mazePtr[i][j] = maze[i][j];
        }
    }

    int result = mazeObstacles(n,m,mazePtr);

    printf("%d\n", result);

    for(int i=0; i<n; i++){
        free(mazePtr[i]);
    }
    free(mazePtr);

    return 0;
}
