#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *array,int length){
    for(int i=length-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]= temp;
            }
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
    bubbleSort(array , length);
    printf("Sorted array(Bubble Sort):-  ");
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
  return 0;
}
