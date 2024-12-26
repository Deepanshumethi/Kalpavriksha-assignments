#include <stdio.h>
#include<string.h>
#include<ctype.h>

int isoperator(char ch){
    if(ch =='+'|| ch == '-' || ch =='/' || ch =='*'){
        return 1;
    }
    return 0;
}

int function_to_perform_operation(int a, int b, char op){
    switch(op){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':if(b==0){
            printf("Error: division by zero condition\n");
            return -1;
        }
        else{
            return a/b;
        }
        default:return -1;
    }
}

int function_to_calucute_the_expression(char *expression){
    int numbers[100];
    char operators[100];
    int num_index = -1;
    int op_index =-1;
    
    for(int i=0;expression[i] != '\0';i++){
        char ch = expression[i];
        if(isspace(ch)){
            continue;
        }
        if(ch == '"'){
            continue;
        }
        if(isdigit(ch)){
            int num = 0;
            while(isdigit(expression[i])){
                num = num*10 + (expression[i]-'0');
                i++;
            }
            i--;
            numbers[++num_index] = num;
        }
        else if(isoperator(ch)){
            while(op_index != -1 && ((operators[op_index] =='*' ||operators[op_index] == '/')|| (ch == '+' || ch =='-'))){
                    int b = numbers[num_index--];
                    int a = numbers[num_index--];
                    char op = operators[op_index--];
                    
                    numbers[++num_index] = function_to_perform_operation(a,b,op);
                }
                operators[++op_index] = ch;
        }
        else{
            return -1;
        }
        
    }
    
    while(op_index != -1){ 
        int b = numbers[num_index--];
        int a = numbers[num_index--];
        char op = operators[op_index--];
        numbers[++num_index] = function_to_perform_operation(a,b,op);
    }
    return numbers[num_index];
    
}
int main() {
    char expression[100];
    
    printf("Enter the expression to caluclate ==> ");
    scanf("%s",expression);
    printf("Your entered expression is ==> %s\n" , expression);
    int result = function_to_calucute_the_expression(expression);
    if(result == -1){
        printf("Error: in evaluating the expression\n");
    }
    else{
        printf("The result after evaluating the expression ==>  %d\n", result);
    }
    return 0;
}