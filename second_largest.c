#include <stdio.h>
#include<string.h>

int stringLength(char *str){
    int length =0;
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

void copy_string(char *str1, char *str2){
    int iterator = 0;
    while(str2[iterator]!='\0'){
        str1[iterator] = str2[iterator];
        iterator++;
    }
    str1[iterator] = '\0';
    return;
}
int main()
{
    char input_string[100];
    char string_sentence_length[100][100];
    int word = 0;
    char *token;
    printf("Enter your sentence to get second largest string:-");
    scanf("%[^\n]s",input_string);
   
   token = strtok(input_string," ");
   
   while(token!=NULL){
    //   printf("%s\n",token);
       copy_string(string_sentence_length[word], token);
       word++;
       token = strtok(NULL," ");
   }
   char largest[100] ;
       char second_largest[100];
       copy_string(largest, string_sentence_length[0]);
    copy_string(second_largest,"");
        
   for(int i=0;i<word;i++){
  
       
       if( stringLength(string_sentence_length[i]) > stringLength(largest)  ){
           copy_string(second_largest,largest);
           copy_string(largest,string_sentence_length[i]);
       }
       if(stringLength(largest)>stringLength(string_sentence_length[i]) && 
       stringLength(second_largest)<stringLength(string_sentence_length[i]) ){
           copy_string(second_largest,string_sentence_length[i]);
       }
    
       
   }
  if(stringLength(second_largest)==0){
       
      printf("No second largest string found\n");
      return 0;
  }
  printf("Second largest:- %s", second_largest);
    return 0;
}
