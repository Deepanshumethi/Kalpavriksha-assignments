#include<stdio.h>
#include<stdlib.h>


void binarySearch(int*array, int length, int key){
   int low = 0;
   int high = length-1;
   
   while(low<=high){
       int mid = low+(high-low)/2;
       
       if(array[mid] == key){
           printf("Key is found at index %d", mid+1);
           return;
       }
       else if(array[mid]<key){
           low = mid+1;
       }
       else{
           high = mid-1;
       }
   }
   
   printf("No matching key found");
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
    scanf("%d",&length);
    if(length>=0){
        printf("Not a valid length");
        return 0;
    }
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
    printf("Enter the value to search:-  ");
    int key;
    scanf("%d",&key);
    binarySearch(array , length , key);
    return 0;
    
}
