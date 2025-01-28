#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *array, int length){
    for(int i=0;i<length-1;i++){
        int min = i;
        for(int j=i+1;j<length;j++){
            if(array[j]<array[min]){
               min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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
    selectionSort(array , length);
    printf("Sorted array(Selection Sort):-  ");
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }

  return 0;
}
