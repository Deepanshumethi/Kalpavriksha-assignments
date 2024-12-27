#include <stdio.h>
#include<string.h>
#include<ctype.h>

int isoperator(char value){
    if(value =='+'|| value == '-' || value =='/' || value =='*'){
        return 1;
    }
    return 0;
}

int function_to_perform_operation(int left_operand, int right_operand, char operator){
    switch(operator){
        case '+':return left_operand+right_operand;
        case '-':return left_operand-right_operand;
        case '*':return left_operand*right_operand;
        case '/':if(right_operand==0){
            return -1;
        }
            return left_operand/right_operand;
        default:return -1;
    }
}
int checkIsSpace(char value) {
    return !(value == ' ' || value == '\t' || value == '\n' || value == '\v' || value == '\f' || value == '\r');
}
int checkIsDigit(char value) {
    return (value >= '0' && value <= '9');
}

int function_to_calculate_the_expression(char *expression){
    int numbers[100];
    char operators_list[100];
    int num_index = -1;
    int op_index = -1;

    for(int i = 0; expression[i] != '\0'; i++){
        char value = expression[i];
        if(!checkIsSpace(value)){
            continue;
        }
        if(value == '"'){
            continue;
        }
        if(checkIsDigit(value)){
            int num = 0;
            while(checkIsDigit(expression[i])){
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            numbers[++num_index] = num;
        }
        else if(isoperator(value)){
            // Error check: Invalid sequences like ++ or --
            if(i > 0 && isoperator(expression[i - 1])){
                return -1;
            }
            if(value == '-' && (i == 0 || isoperator(expression[i - 1]) || expression[i - 1] == '(')){
                // Handle negative numbers
                i++;
                int num = 0;
                while(checkIsDigit(expression[i])){
                    num = num * 10 + (expression[i] - '0');
                    i++;
                }
                i--;
                numbers[++num_index] = -num;
            } else {
                while(op_index != -1 && ((operators_list[op_index] == '*' || operators_list[op_index] == '/') || (value == '+' || value == '-'))){
                    int right_operand = numbers[num_index--];
                    int left_operand = numbers[num_index--];
                    char operator = operators_list[op_index--];

                    numbers[++num_index] = function_to_perform_operation(left_operand, right_operand, operator);
                }
                operators_list[++op_index] = value;
            }
        }
        else{
            return -1;
        }
    }

    while(op_index != -1){
        int right_operand = numbers[num_index--];
        int left_operand = numbers[num_index--];
        char operator = operators_list[op_index--];
        numbers[++num_index] = function_to_perform_operation(left_operand, right_operand, operator);
    }
    return numbers[num_index];
}

int main() {
    char expression[100];

    printf("Enter the expression to calculate ==> ");
    scanf("%[^\n]", expression);
    printf("Your entered expression is ==> %s\n", expression);
    int result = function_to_calculate_the_expression(expression);
    if(result == -1){
        printf("Error: Invalid or malformed expression\n");
    }
    else{
        printf("The result after evaluating the expression ==> %d\n", result);
    }
    return 0;
}
