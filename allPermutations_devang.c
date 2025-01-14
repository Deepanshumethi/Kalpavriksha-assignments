#include <stdio.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int custom_length(char *s){
    int count = 0;
    while(s[count]!= '\0'){
        count++;
       
    }
    return count;
}
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s ", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap((str + l), (str + i));
        permute(str, l + 1, r);
        swap((str + l), (str + i)); 
    }
}

int main() {
    char string[20]; 
    printf("Enter string: ");
    scanf("%s", string);
    
    int n = custom_length(string);
    printf("Permutations:- ");
    permute(string, 0, n - 1);
    
    return 0;
}
