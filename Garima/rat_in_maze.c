#include<stdio.h>
#include<string.h>
void solve(int i, int j, int(*array)[4] , int size, char*str , int(*check)[4]){
    
    if(i == size-1 && j==size-1){
        printf("%s ", str);
        return;
    }
    //downward
    if(i+1<size && check[i+1][j] ==0 && array[i+1][j] == 1 ){
        check[i][j] = 1;
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, "D");
        solve(i+1,j,array,size,newStr,check);
        check[i][j] = 0;
    }
    //left
    if(j-1>=0 && check[i][j-1] == 0 && array[i][j-1] == 1){
        check[i][j]=1;
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, "L");
        solve(i,j-1,array,size,newStr,check);
        check[i][j]=0;
    }
    
    //rigt
    if(j+1<size && check[i][j+1] == 0 && array[i][j+1] == 1){
        check[i][j] =1;
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, "R");
        solve(i,j+1,array,size,newStr,check);
        check[i][j] = 0;
    }
    
    //Up
    if(i-1 >=0 && check[i-1][j] == 0 && array[i-1][j] == 1){
        check[i][j] = 1;
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, "U");
        solve(i-1,j,array,size,newStr,check);
        check[i][j] = 0;
    }
    
    return;
}

int main(){
    int array[4][4] = {1,0,0,0,
                       1,1,0,0,
                       1,1,0,0,
                       0,1,1,1};
    int check[4][4] = {0};
    int size = 4;
    if(array[0][0] == 1){
        solve(0,0,array,size,"",check);
    }
    
                        
}