#include<stdio.h>
#include<stdlib.h>

void mergeArray(int *array, int low, int mid, int high){
    int length = high-low+1;
    int* temp = malloc(length*sizeof(int));
    int left = low;
    int right = mid+1;
    int count=0;
    while(left<=mid && right<=high){
        if(array[left]<=array[right]){
            temp[count++] = array[left++];
        }else{
            temp[count++] = array[right++];
        }
    }
    while(left<=mid){
        temp[count++] = array[left++];
    }
    while(right<=high){
        temp[count++] = array[right++];
    }
    for(int i=low;i<=high;i++){
        array[i] = temp[i-low];
    }
}

void mergeSort(int *array,int left,int right){
    if(left>=right){
        return;
    }
    int mid = left + (right-left)/2;
    mergeSort(array,left,mid);
    mergeSort(array,mid+1,right);
    mergeArray(array,left,mid,right);
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
    mergeSort(array , 0, length-1);
    printf("Sorted array(Selection Sort):-  ");
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
  return 0;
}
