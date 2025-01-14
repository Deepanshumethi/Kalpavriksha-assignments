#include <stdio.h>

void copyStr(char *str1, char* str2){
    int i=0;
    while(str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return;
}

void countSay(char* str) {
    char result[100];
    int i = 0, pos = 0;

    while (str[i] != '\0') {
        int k = 0;
        char j = str[i];
        while (str[k + i] == j) {
            k++;
        }
        char kStr[10];
        int kLen = 0;
        int tempK = k;
        while (tempK > 0) {
            kStr[kLen++] = (tempK % 10) + '0';
            tempK /= 10;
        }
        for (int m = kLen - 1; m >= 0; m--) {
            result[pos++] = kStr[m];
        }
        result[pos++] = j;
        i += k;
    }
    result[pos] = '\0';
    copyStr(str, result);
}

int main() {
    char str[100] = "1";
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        countSay(str);
    }
    printf("%s", str);
    return 0;
}
