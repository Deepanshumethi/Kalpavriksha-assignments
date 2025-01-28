#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

typedef struct store {
    char ch;
    int count;
    int index;
} store;

int main() {
    char str[MAX_LENGTH];
    scanf("%[^\n]", str);
    getchar();
    char replace;
    scanf("%c",&replace);
    store storage[MAX_LENGTH] = {0};
    int p = 0;

    for (int i = 0; i < strlen(str); i++) {
        int k = 0;
        if(str[i] ==' '){
            continue;
        }
        while (k < p) {
            if (storage[k].ch == str[i]) {
                storage[k].count++;
                break;
            }
            k++;
        }
        if (k == p) {
            storage[p].ch = str[i];
            storage[p].count = 1;
            storage[p].index = i;
            p++;
        }
    }
    

    for (int i = 0; i < p; i++) {
      if(storage[i].count == 1){
          str[storage[i].index] = replace;
          break;
      }
    }
    printf("%s",str);

    return 0;
}
