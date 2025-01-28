#include<stdio.h>
#include<stdlib.h>


void getPairSum(int *array, int length, int target){
    
    int low = 0;
    int high = length-1;
    int found = 0;
    while(low<high){
        int tempSum = array[low] + array[high] ;
        if(tempSum == target){
            printf("Target sum found on the addintion of array indexies %d and %d (%d+%d)\n", low,high, array[low],array[high]);
            found = 1;
            low++;
            high--;
        }
        else if(tempSum > target){
            high--;
        }
        else{
            low++;
        }
    }
    if(found == 0){
    printf("No pair found with the target sum");
    }
}


int checkSorted(int*array, int length){
    for(int i=0;i<length-1;i++){
        if(array[i]>array[i+1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int length;
    printf("Enter length of the array:-  ");
    if(length>=0){
        printf("Not a valid length");
        return 0;
    }
    scanf("%d",&length);
    int*array = (int *) malloc(length * sizeof(int));
    printf("Enter the value of the array in sorted manner:-  ");
    for(int i=0;i<length;i++){
        scanf("%d", &array[i]);
    }
    
    int check = checkSorted(array,length);
    if(check == 0){
        printf("Entered array is not in sorted manner");
        return 0;
    }
    printf("Enter the target sum to search:-  ");
    int target;
    scanf("%d",&target);
    getPairSum(array , length , target);
    return 0;
    
}
