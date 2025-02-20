#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char str[100];
}focus;

int findmax(char* str1, char*str2){
    int p = strlen(str1);
    int q = strlen(str2);
    
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(str1[i] == str2[j]){
                return 0;
            }
        }
    }
    return p*q;
    
}

int main()
{
    int size = 0;
    focus *arr = malloc(size*sizeof(focus));
    char str[100];
    while(scanf("%s",str) == 1){
        size++;
        arr = realloc(arr ,size*sizeof(focus));
        strcpy(arr[size-1].str,str);
        
        if(getchar() == '\n'){
            break;
        }
    }
    
    
    int max = 0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            int m = findmax(arr[i].str,arr[j].str);
            if(m > max){
                max = m;
            }
        }
    }
    
    printf("max %d",max);
   
}
