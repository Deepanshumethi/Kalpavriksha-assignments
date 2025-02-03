#include<stdio.h>
#include<stdlib.h>

void all_subsets(int*array,int size,int *output,int index,int oIndex,int target ,int* flag){
    if(index>=size){
        // printf("subset->  ");
        int sum = 0;
        for(int i=0;i<oIndex;i++){
           sum+=output[i];
        }
        if(sum==target){
            *flag = 1;
            return;
        }
        // printf("\n");
        return;
    }
    if(*flag ==1){
        return;
        
    }
    
    
        all_subsets(array,size,output,index+1,oIndex,target,flag);
        output[oIndex] = array[index];
         all_subsets(array,size,output,index+1,oIndex+1,target,flag);
         
    
    
}

int main(){
    int* array = malloc(sizeof(int));
    int input;
    int size=1;
    while(scanf("%d",&input)==1){
        array[size-1] = input;
       
        
        if(getchar()=='\n'){
            break;
        }
        size++;
        array = realloc(array,size*sizeof(int));
    }
    int target;
    printf("Enter target:-");
    scanf("%d",&target);
    
    // for(int i=0;i<size;i++){
    //     printf("%d ",array[i]);
    // }
    
    int *output = malloc(size*sizeof(int));
    int index = 0;
    int flag = 0;
    all_subsets(array,size,output,0,0,target,&flag);
    if(flag == 1){
        printf("True");
    }
    else{
        printf("False");
    }
    
    return 0;
}