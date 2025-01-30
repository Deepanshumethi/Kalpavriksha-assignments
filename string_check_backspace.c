#include<stdio.h>

int string_length(char* string){
    int count = 0;
    while(string[count] != '\0'){
        count++;
    }
    return count;
}

void makeValidString(char*str, char*copy){
    int length = string_length(str);
    int index = 0;
    for(int i=0;i<length;i++){
        if(index == 0 && str[i] == '#'){
            continue;
        }
        else if(str[i] == '#' && index>0){
            index--;
        }else{
            copy[index] = str[i];
            index++;
        }  
    }
    copy[index] = '\0';
}

int string_compare(char* string_one, char* string_two){
    int lenght_one = string_length(string_one);
    int lenght_two = string_length(string_two);
    if(lenght_one !=  lenght_two){
        return 1;
    }
    
    for(int i=0;i<lenght_one;i++){
        if(string_one[i] != string_two[i]){
            return 1;
        }
    }
    return 0;
}
int main(){
    
    char s[100];
    char t[100];
    printf("Enter the first string:- ");
    scanf("%s",s);
    getchar();
    printf("Enter the second string:- ");
    scanf("%s",t);
    
    char sCopy[100];
    char tCopy[100]; 
    
    makeValidString(s,sCopy);
    makeValidString(t,tCopy);
    
    
    if(string_compare(sCopy,tCopy) == 0){
        printf("True");
    }
    else{
        printf("False");
    }
    
    
    return 0;
}
