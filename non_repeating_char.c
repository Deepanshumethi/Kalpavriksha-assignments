#include <stdio.h>
#include<string.h>
typedef struct {
    char ch;
    int k;
}map;

int main()
{
    char str[100000];
    
    scanf("%s",str);
    
    
    map array[strlen(str)];
    int c=0;
    
    for(int i=0;i<strlen(str);i++){
        int p=0;
        for(int j=0;j<c;j++){
            if(array[j].ch == str[i]){
                array[j].k = array[j].k + 1;
                printf("-1");
                p=1;
                break;
            }
        }
        if(p==0){
             array[c].ch = str[i];
                array[c].k = 1;
                c++;
                printf("%c",str[i]);
        }
    }

    return 0;
}
