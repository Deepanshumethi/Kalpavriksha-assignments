#include <stdio.h>
#include <stdlib.h>

int calculateSum(int numbers[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += numbers[i];
    return sum;
}

void findCombinations(int *nums, int combination[], int combinationIndex, int numIndex, int target, int size)
{
    int combinationSum = calculateSum(combination, combinationIndex);
    if (combinationSum == target)
    {
        printf("[");
        for (int i = 0; i < combinationIndex; i++)
        {
            printf("%d ", combination[i]);
        }
        printf("]\n");
    }
    if (combinationSum > target)
        return;

    for (int i = numIndex; i < size; i++)
    {
        combination[combinationIndex] = nums[i];
        findCombinations(nums, combination, combinationIndex + 1, i, target, size);
    }
}

int main()
{
    int num;
    char ch;
    int *nums = malloc(sizeof(int));
    int index = 0;
    while ((scanf("%d", &num)) == 1)
    {
        nums = realloc(nums, (index + 1) * sizeof(int));
        nums[index++] = num;
        if ((ch = getchar()) == '\n')
            break;
    }
    int size = index;
    int target;
    scanf("%d", &target);
    printf("Input array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\nTarget is: %d\n", target);
    int combination[100];
    int combinationIndex = 0;
    int numIndex = 0;
    printf("Output is: \n");
    findCombinations(nums, combination, combinationIndex, numIndex, target, size);
    free(nums);
    return 0;
}
