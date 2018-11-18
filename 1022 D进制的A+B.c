#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    int a, b, D;
    scanf("%d %d %d", &a, &b, &D);
    
    int result = a + b;
    
    int resultDec[40];
    int i = 0;
    
    //注意特殊值为0的情况。
    if (result == 0) {
        printf("0\n");
    }
    while (result != 0) {
        resultDec[i++] = result % D;
        result /= D;
    }
    
    for (i = i-1; i>=0; i--) {
        printf("%d", resultDec[i]);
    }
    
    return 0;
}

