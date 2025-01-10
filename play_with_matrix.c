#include<stdio.h>
#include<stdlib.h>

void roatate90degree(int**matrix,int size){
    //transpose the matrix
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    
    //swap columns
    int  first= 0;
    int  last = size-1;
    
    while(last>first){
        for(int i=0;i<size;i++){
            int temp = matrix[i][last];
            matrix[i][last] = matrix[i][first];
            matrix[i][first] = temp;
        }
        first++;
        last--;
    }
    
    
}

void rowWiseLeft(int **matrix,int size){
    int *temp = calloc(size,sizeof(int));
    for(int i=0;i<size;i++){
        temp[i] = matrix[i][0];
    }
    
    for(int i=0;i<size;i++){
        for(int j=1;j<size;j++){
            int temp = matrix[i][j];
             matrix[i][j] = matrix[i][j-1];
            matrix[i][j-1] =temp;
        }
    }
    
    for(int i=0;i<size;i++){
        matrix[i][size-1] = temp[i];
    }
    free(temp);
}

void rowWiseRight(int **matrix,int size){
    int *temp = calloc(size , sizeof(int));
    
    for(int i=0;i<size;i++){
        temp[i] = matrix[i][size-1];
    }
    for(int i=0;i<size;i++){
        for(int j=size-2;j>=0;j--){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][j+1];
            matrix[i][j+1] = temp;
        }
    }
    for(int i=0;i<size;i++){
        matrix[i][0] = temp[i];
    }
     free(temp);
}

void columnWiseUp(int **matrix , int size){
    int *temp = calloc(size,sizeof(int));
    for(int i=0;i<size;i++){
        temp[i]=matrix[0][i];
    }
    
    for(int i=1;i<size;i++){
        for(int j=0;j<size;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i-1][j];
            matrix[i-1][j]=temp;
        }
    }
    
    for(int i=0;i<size;i++){
        matrix[size-1][i] = temp[i];
    }
     free(temp);
}

void columnWiseDown(int **matrix,int size){
    int *temp = calloc(size, sizeof(int));
    
    for(int i=0;i<size;i++){
        temp[i] = matrix[size-1][i];
    }
    for(int i=size-2;i>=0;i--){
        for(int j=0;j<size;j++){
            int temp = matrix[i+1][j];
            matrix[i+1][j]=matrix[i][j];
            matrix[i][j]=temp;
        }
    }
    for(int i=0;i<size;i++){
        matrix[0][i] = temp[i];
    }
     free(temp);
}

int main(){
    int size;
    printf("Enter the size of square matrix:- ");
    scanf("%d",&size);
    
    int**matrix = calloc(size , sizeof(int *));
    for(int i=0;i<size;i++){
        matrix[i] = calloc(size, sizeof(int));
    }
    printf("Enter the value of the matrix:-\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            
            scanf("%d",&matrix[i][j]);
        }
    }
    int loop = 0;
    
  while(loop ==0){
    printf("\n\n");
    printf("Choose option to do with the matrix ==> \n");
    printf("\n");
    printf("Enter 1 for rotate matrix by 90 degrees\n");
    printf("Enter 2 for row-wise left roatetion\n");
    printf("Enter 3 for row-wise right rotation\n");
    printf("Enter 4 for column-wise up rotation\n");
    printf("Enter 5 for column-wise down rotation\n");
    printf("Enter any key to exit\n");
    printf("Input :- ");
    int input;
    scanf("%d" , &input);
    int steps;
    if(input == 1 ||input == 2 ||input == 3 ||input == 4 ||input == 5){
    printf("Enter number of steps for rotation:-");
    scanf("%d",&steps);
    }
    
    if(input ==1){
        if(steps>=4){
            steps = steps%4;
        }
    }
    else{
        if(steps>=size){
            steps = steps/size;
        }
    }
    
    
    switch(input){
        case 1:
                for(int i=0;i<steps;i++){
                  roatate90degree(matrix,size);
                }
                break;
                
        case 2:
                for(int i=0;i<size;i++){
                    rowWiseLeft(matrix,size);
                }
                 break;
        case 3:
                 for(int i=0;i<size;i++){
                    rowWiseRight(matrix,size);
                }
                 break;
        case 4:
                 for(int i=0;i<size;i++){
                    columnWiseUp(matrix,size);
                }
                 break;
        case 5:
                for(int i=0;i<size;i++){
                    columnWiseDown(matrix,size);
                }
                 break;
        default:
                printf("Exit done");
                loop = 1;
                exit(0);
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("-: Now all changes will happen on the updated matrix :-");
}
for (int i = 0; i < size; i++) {
    free(matrix[i]);
}
free(matrix);
return 0;

}
