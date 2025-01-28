#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *array, int length){
    for(int i=0;i<length;i++){
        int j=i;
        while(j>0 && array[j-1]>array[j]){
           int temp = array[j];
           array[j] = array[j-1];
           array[j-1] = temp;
           j--;
        }
    }
}

int main(){
    int length;
    printf("Enter length of the array:-  ");
    scanf("%d",&length);
    if(length>=0){
        printf("Not a valid length");
        return 0;
    }
    int*array = (int *) malloc(length * sizeof(int));
    printf("Enter the value of the array:-  ");
    for(int i=0;i<length;i++){
        scanf("%d", &array[i]);
    }
    insertionSort(array , length);
    printf("Sorted array(Selection Sort):-  ");
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
  return 0;
}
