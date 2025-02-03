#include <stdio.h>
#include <stdlib.h>

int isSafe(char **board, int row, int col, int size)
{
    
    int r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return 0;
        r--;
        c--;
    }

   
    r = row;
    c = col;
    while (c >= 0)
    {
        if (board[r][c] == 'Q')
            return 0;
        c--;
    }

    c = col;
    while (r < size && c >= 0)
    {
        if (board[r][c] == 'Q')
            return 0;
        r++;
        c--;
    }

    return 1;
}

void printBoard(char **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void solveNQueens(char **board, int col, int size)
{
    if (col == size)
    {
        printBoard(board, size);
        printf("\n");
        return;
    }

    for (int row = 0; row < size; row++)
    {
        if (isSafe(board, row, col, size))
        {
            board[row][col] = 'Q';  
            solveNQueens(board, col + 1, size);  
            board[row][col] = '.';  
        }
    }
}

int main()
{
    int boardSize;
    scanf("%d", &boardSize);
    printf("Input: \n");
    printf("n: %d\n", boardSize);

    
    char **board = (char **)malloc(boardSize * sizeof(char *));
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = (char *)malloc(boardSize * sizeof(char));
    }

    
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = '.';
        }
    }

    solveNQueens(board, 0, boardSize);



    return 0;
}
