#include<stdio.h>
#include<stdlib.h>

void swap(int* item1, int* item2){
    int temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

int partition(int *array,int low,int high){
    int pivot = array[low];
    int i=low;
    int j=high;
    
    while(i<j){
        while(array[i]<=pivot && i<=high-1){
            i++;
        }
        while(array[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(&array[i],&array[j]);
        }
    }
     swap(&array[low],&array[j]);
        return j;
}

void quickSort(int *array,int low,int high){
  if(low<high){
      int partitionIndex = partition(array,low,high);
      quickSort(array,low,partitionIndex-1);
      quickSort(array,partitionIndex+1,high);
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
    quickSort(array , 0, length-1);
    printf("Sorted array(Selection Sort):-  ");
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
  return 0;
}
