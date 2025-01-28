#include <stdio.h>
#include<stdlib.g>

void swap(int*a,int*b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int **arr = malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        arr[i] = malloc(n*sizeof(int));
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(&arr[i][j],&arr[j][i]);
        }
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
