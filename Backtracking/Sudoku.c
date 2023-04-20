#include <stdio.h>
#include <math.h>

#define N 9

int isSafe(int board[N][N], int row, int col, int num)
{
    // Check if the number we are trying to place is already present in that row
    for (int d = 0; d < N; d++)
    {
        if (board[row][d] == num) {
            return 0;
        }
    }

    // Check if the number we are trying to place is already present in that column
    for (int r = 0; r < N; r++)
    {
        if (board[r][col] == num)
        {
            return 0;
        }
    }

    // Check if the number we are trying to place is already present in the corresponding square
    int sqrtN = (int) sqrt(N);
    int boxRowStart = row - row % sqrtN;
    int boxColStart = col - col % sqrtN;

    for (int r = boxRowStart; r < boxRowStart + sqrtN; r++)
    {
        for (int c = boxColStart; c < boxColStart + sqrtN; c++)
        {
            if (board[r][c] == num)
            {
                return 0;
            }
        }
    }

    // If there is no clash, it's safe
    return 1;
}

int solveSudoku(int board[N][N])
{
    int row = -1;
    int col = -1;
    int isEmpty = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;

                // We still have some remaining missing values in Sudoku
                isEmpty = 0;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // No empty space left
    if (isEmpty)
    {
        return 1;
    }

    // Else for each-row backtrack
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (solveSudoku(board))
            {
                return 1;
            }
            else
            {
                // Replace it
                board[row][col] = 0;
            }
        }
    }
    return 0;
}

void print(int board[N][N])
{
    // We got the answer, just print it
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");

        if ((r + 1) % (int) sqrt(N) == 0)
        {
            printf("\n");
        }
    }
}

// Driver code
int main()
{
    int board[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
  
       int N = board.length;

  

        if (solveSudoku(board, N)) 

        {

            // print solution

            print(board, N);

        }

        else {

            printf("No solution");

        }

    }

