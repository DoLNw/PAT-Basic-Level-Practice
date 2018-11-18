#include <stdio.h>

int main() {
    printf("Hello World!\n");
    
    //这个估计既可以用int，也可以用char来输入。
    char a[11], b[11], aa, bb;
    int aCount = 0, bCount = 0;
    int aResult = 0, bResult = 0;
    
    scanf("%s %c %s %c", a, &aa, b, &bb);
    
    for (int i=0; a[i] != '\0'; i++) {
        if (a[i] == aa) {
            aCount++;
        }
    }
    for (int i=0; b[i] != '\0'; i++) {
        if (b[i] == bb) {
            bCount++;
        }
    }
    
    for (int i=0; i<aCount; i++) {
        aResult = aResult*10 + aa-48;
    }
    for (int i=0; i<bCount; i++) {
        bResult = bResult*10 + bb-48;
    }
    
    printf("%d\n", aResult+bResult);
    
    return 0;
}

