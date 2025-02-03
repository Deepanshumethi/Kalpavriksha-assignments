#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchWord(char** board, char* word, int row, int col, int index, int numRows, int numCols) {
    if (index == strlen(word))
        return 1;

    if (row < 0 || col < 0 || row >= numRows || col >= numCols || board[row][col] != word[index] || board[row][col] == '!')
        return 0;

    char temp = board[row][col];
    board[row][col] = '!';

    int top = searchWord(board, word, row - 1, col, index + 1, numRows, numCols);
    int right = searchWord(board, word, row, col + 1, index + 1, numRows, numCols);
    int bottom = searchWord(board, word, row + 1, col, index + 1, numRows, numCols);
    int left = searchWord(board, word, row, col - 1, index + 1, numRows, numCols);

    board[row][col] = temp;

    return top || right || bottom || left;
}

int wordExists(char** board, int numRows, int numCols, char* word) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (board[i][j] == word[0] && searchWord(board, word, i, j, 0, numRows, numCols)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int numRows, numCols;

    printf("Enter number of rows: ");
    scanf("%d", &numRows);
    printf("Enter number of columns: ");
    scanf("%d", &numCols);

    char** board = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++) {
        board[i] = (char*)malloc(numCols * sizeof(char));
    }

    printf("Enter the 2D array of characters (row by row):\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    char word[100];
    printf("Enter the word to search for: ");
    scanf("%s", word);

    int result = wordExists(board, numRows, numCols, word);

    if (result)
        printf("True\n");
    else
        printf("False\n");

    for (int i = 0; i < numRows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
