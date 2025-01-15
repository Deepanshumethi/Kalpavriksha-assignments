#include <stdio.h>

void swap(int*a,int*b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int arr[n][n];
    
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
