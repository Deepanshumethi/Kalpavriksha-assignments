#include<stdio.h>
#include<stdlib.h>


typedef struct sortStr {
    char str[10];
    char sort[10];
} sortStr;

int custom_length(char *s){
    int count = 0;
    while(s[count]!= '\0'){
        count++;
       
    }
    return count;
}
int customCmp(char* str1 , char* str2){
    int n = custom_length(str1);
    
    int i=0;
    for(int i=0;i<n;i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

char* sortString(char *str, char *new) {
    strcpy(new, str);
    int len = strlen(new);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (new[i] > new[j]) {
                char temp = new[i];
                new[i] = new[j];
                new[j] = temp;
            }
        }
    }
    return new;
}


int compare(const void *a, const void *b) {
    return customCmp(((sortStr*)a)->sort, ((sortStr*)b)->sort);
}

int main() {
    int n;
    scanf("%d", &n);

    char **arrStr = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arrStr[i] = malloc(10 * sizeof(char));
    }

    sortStr jointArr[n];
    char new[10];
    for (int i = 0; i < n; i++) {
        printf("Enter string: ");
        scanf("%s", arrStr[i]);

        sortString(arrStr[i], new);
        
        strcpy(jointArr[i].str, arrStr[i]);
        strcpy(jointArr[i].sort, new);
    }

   
    printf("Grouped strings:\n");
    for (int i = 0; i < n; ) {
        printf("Group %d: " , i+1);
        
       
        while (i < n && strcmp(jointArr[i].sort, jointArr[i+1].sort) == 0) {
            printf("%s ", jointArr[i].str);
            i++;
        }
        printf("%s\n", jointArr[i].str); 
        i++; 
    }

  
    for (int i = 0; i < n; i++) {
        free(arrStr[i]);
    }
    free(arrStr);

    return 0;
}
