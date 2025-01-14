#include <stdio.h>
#define MAX_LEN 15
int custom_length(char *s){
    int count = 0;
    while(s[count]!= '\0'){
        count++;
       
    }
    return count;
}
int custom_compare(char *s1,char* s2,int m){
    for(int i=0;i<m;i++){
        if(s1[i] != s2[i]){
            return 1;
        }
    }
    return 0;
}
int main()
{
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    printf("Enter the first string:-");
    scanf("%[^\n]",s1);
    getchar();
    printf("Enter the second string:-");
    scanf("%[^\n]",s2);
    int m = custom_length(s1);
    int k = custom_length(s2);
    if(m != k){
        printf("False");
        return 1;
    }
    
    if(custom_compare(s1,s2,m) == 0){
        printf("True");
        return 0;
    }
    int s=0;
    int indexes[m];
    for(int i=0;i<m;i++){
        if(s1[i]!=s2[i]){
            indexes[s]=i;
            s++;
        }
    }
    if(s==2){
        int a = indexes[0];
        int b = indexes[1];
        int temp = s1[a];
        s1[a] = s1[b];
        s1[b] = temp;
        
        if(custom_compare(s1,s2,m) == 0){
             printf("True");
             return 0;
        }  
    }
        printf("False");
    return 0;
}
