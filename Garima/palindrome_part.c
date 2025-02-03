#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalindrom(char word[], int size)
{
    int s = 0, e = size - 1;
    while (s <= e)
    {
        if (word[s] == word[e])
        {
            s++;
            e--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
void palindrome_part(char string[], char result[100][100], int resIndx, int idx, int strSize)
{
    if (idx == strSize)
    {
        printf("[");
        for (int i = 0; i < resIndx; i++)
        {
            printf("%s ", result[i]);
        }
        printf("]\n");
        return;
    }
    char check[100];
    int j = 0;
    for (int i = idx; i < strSize; i++)
    {
        check[j++] = string[i];
        check[j] = '\0';
        if (checkPalindrom(check, j))
        {
            strcpy(result[resIndx], check);
            palindrome_part(string,result, resIndx + 1, i + 1, strSize);
            strcpy(result[resIndx], "");
        }
    }
}
int main()
{
    char input_string[100];
    scanf("%s",input_string);
    printf("Input string is: %s\n", input_string);
    char result[100][100];
    int resIndx = 0;
    int strSize = strlen(input_string);
    printf("Output string is: \n");
    palindrome_part(input_string, result, resIndx, 0, strSize);
    return 0;
}