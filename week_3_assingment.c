#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLUMNS 101


int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
int countLength(char *str){
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
int copyString(char *str1, char *str2){
    int iterator = 0;
    while(str2[iterator] != '\0'){
        str1[iterator] = str2[iterator];
        iterator++;
    }
    str1[iterator] = '\0';
}

int main() {
   int rows, cols;
   char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH];
    printf("Enter number of rows (1-10): ");
    scanf("%d", &rows);
    while (rows < 1 || rows > 10) {
        printf("Invalid input. Enter number of rows (1-10): ");
        scanf("%d", &rows);
    }
    printf("Enter number of columns (1-101): ");
    scanf("%d", &cols);
    while (cols < 1 || cols > 101) {
        printf("Invalid input. Enter number of columns (1-101): ");
        scanf("%d", &cols);
    }
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
    int vowelCount = 0;
    char longestName[MAX_NAME_LENGTH] = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isVowel(names[i][j][0])) {
                vowelCount++;
            }
            if (countLength(names[i][j]) > countLength(longestName)) {
                copyString(longestName, names[i][j]);
            }
        }
    }
    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);
    return 0;
}
