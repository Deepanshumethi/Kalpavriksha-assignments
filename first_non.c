#include <stdio.h>
#include <string.h>

typedef struct {
    char ch;
    int k;
} map;

int main() {
    char str[100000];
    scanf("%s", str);
    
    map array[256] = {0}; 
    int c = 0;
    char result[strlen(str) + 1];
    int resIndex = 0;
    
    for (int i = 0; i < strlen(str); i++) {
        int p = 0;
        for (int j = 0; j < c; j++) {
            if (array[j].ch == str[i]) {
                array[j].k++;
                p = 1;
                break;
            }
        }
        if (p == 0) {
            array[c].ch = str[i];
            array[c].k = 1;
            c++;
        }
        
        int found = 0;
        for (int j = 0; j < c; j++) {
            if (array[j].k == 1) {
                result[resIndex++] = array[j].ch;
                found = 1;
                break;
            }
        }
        if (!found) {
            result[resIndex++] = '-';
            result[resIndex++] = '1';
        }
    }
    
    result[resIndex] = '\0';
    printf("%s\n", result);
    
    return 0;
}
