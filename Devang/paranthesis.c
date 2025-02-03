#include<stdio.h>
#include<string.h>
void solve(int open, int close,int size, char* str){
    if(open == size && close == size){
        printf("%s ",str);
        return;
    }
    
    if(open == close){
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, "(");
        solve(open+1,close,size,newStr);
    }
    else if(open >=size ){
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, ")");
        solve(open,close+1,size,newStr);
    }
    
    else{
        char newStr[100];
        strcpy(newStr, str);
        strcat(newStr, "(");
        solve(open+1,close,size,newStr);
        char newStr2[100];
        strcpy(newStr2, str);
        strcat(newStr2, ")");
        solve(open,close+1,size,newStr2);
    }
    
}

int main(){
    int n;
    scanf("%d",&n);
    
    solve(0,0,n,"");
    return 0;
}