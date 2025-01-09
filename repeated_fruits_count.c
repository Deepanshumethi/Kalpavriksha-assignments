#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 15


int main(){
    int row;
    int cols;
    printf("Enter the number of rows:- ");
    scanf("%d",&row);
    printf("Enter the number of columns:- ");
    scanf("%d",&cols);
    
    char input_data[row][cols][MAX_LENGTH];
    char all_fruits[row*cols][MAX_LENGTH];
    int *count = calloc(row*cols, sizeof(int));
    int j=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
              printf("Enter the fruit name for (%d , %d):-",i,j);
            scanf("%s",input_data[i][j]); 
        }
    }
    int iterator=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            for(int k=0;k<row*cols;k++){
                if(strcmp(input_data[i][j],all_fruits[k])==0){
                    count[k]=count[k]+1;  
                }
            }
            strcpy(all_fruits[iterator],input_data[i][j]);
                    iterator++;
        }
    }
    printf("\n");
    printf("\n");
    for(int i=0;i<row*cols;i++){
       if(count[i]>=1){
           printf("%s :- %d \n",all_fruits[i], count[i]+1);
       }
    }
    
}
