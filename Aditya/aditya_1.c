#include <stdio.h>



void print_all_combinations(char *digits, int length, char dictionary[][10],char* output,int index, int oindex){
    if(index>=length){
        output[oindex] = '\0';
        
            printf(",%s ",output);
        
        return;
    }
    int number = digits[index]-'0';
    char *value = dictionary[number];
    int len = 0;

    while (value[len] != '\0') {
       
        len++;
    }
    // printf("")
    for(int i=0;i<len;i++){
        output[oindex] = value[i];
        print_all_combinations(digits,length,dictionary,output,index+1,oindex+1);
        // oindex-1;
    }
}

int main() {
    char digits[4];
    scanf("%s", digits);
    // printf("%s", digits);

    char dictionary[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int length = 0;

    while (digits[length] != '\0') {
        
        length++;
       
    }
    

    printf("\n");
    // printf("%d", length);
    char output[length];
    int start = digits[0]-'0';
    print_all_combinations(digits, length, dictionary,output,0, 0);

    return 0;
}
