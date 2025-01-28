#include<stdio.h>
#include<stdlib.h>


void linearSearch(int*array, int length, int key){
    for(int i=0;i<length;i++){
        if(array[i] == key){
            printf("Key is found at index %d",i+1);
            return;
        }
    }
    printf("No matching key found");
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
    printf("Enter the value to search:-  ");
    int key;
    scanf("%d",&key);
    linearSearch(array , length , key);
    return 0;
}
