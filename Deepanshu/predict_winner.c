#include <stdio.h>
#include <stdlib.h>

int canPlayer1Win(int *nums, int player1Score, int player2Score, int isPlayer1Turn, int start, int end)
{
    if (start > end)
    {
        return player1Score >= player2Score;
    }

    if (isPlayer1Turn)
    {
        return canPlayer1Win(nums, player1Score + nums[start], player2Score, 0, start + 1, end) || 
               canPlayer1Win(nums, player1Score + nums[end], player2Score, 0, start, end - 1);
    }
    else
    {
        return canPlayer1Win(nums, player1Score, player2Score + nums[start], 1, start + 1, end) && 
               canPlayer1Win(nums, player1Score, player2Score + nums[end], 1, start, end - 1);
    }
}

int predictWinner(int *nums, int size)
{
    return canPlayer1Win(nums, 0, 0, 1, 0, size - 1);
}

int main()
{
    printf("Input: \n");
    int num;
    int *numsArray = malloc(sizeof(int));
    int index = 0;
    char ch;

    while ((scanf("%d", &num)) == 1)
    {
        numsArray = (int *)realloc(numsArray, (index + 1) * sizeof(int));
        numsArray[index++] = num;
        if ((ch = getchar()) == '\n')
            break;
    }

    int arraySize = index;
    int result = predictWinner(numsArray, arraySize);

    if (result == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    free(numsArray);
    return 0;
}
