#include <stdio.h>
#include<stdlib.h>
int main()
{
    int rows;
    int cols;
    printf("Enter row:-");
    scanf("%d",&rows);
    printf("Enter cols:-");
    scanf("%d",&cols);
    
    int **array = malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        array[i] = malloc(cols*sizeof(int));
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // printf("Enter the data of index (%d , %d):- ",i,j);
            scanf("%d",&array[i][j]);
        }
    }
    
    int target ;
    printf("Enter target:- ");
    scanf("%d",&target);
  
    int r = 0;
    int c = cols-1;
    
    while(r<rows && c>=0){
        if(array[r][c] == target){
            printf("True");
            return 0;
        }
        else if(array[r][c] > target){
            c--;
        }
        else{
            r++;
        }
    }
   printf("False");
    
    

    return 0;
}
