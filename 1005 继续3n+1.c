#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int row;
    int key[100];
    //注意：有时候会出现段错误，可能是数组不够大导致数组越界导致的。
    int num[10000];
    
    scanf("%d", &row);
    
    for (int i=0; i<row; i++) {
        scanf("%d", key+i);
    }
    int num1 = 0;
    for (int i=0; i<row; i++) {
        num1 = key[i];
        while (num1!=1) {
            if (num[num1] != 1) {
                if (num1 != key[i]) {
                    num[num1] = 1;
                }
                if (num1%2==0) num1 /= 2;
                else num1 = (num1*3+1)/2;
            } else break;
        }
    }
    int temp = 0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<i; j++) {
            if (key[i]>key[j]) {
                temp = key[i];
                key[i] = key[j];
                key[j] = temp;
            }
        }
    }
    int isFirst = 1;
    for (int i=0; i<row; i++) {
        if (num[key[i]]!=1) {
            if (isFirst) {
                isFirst = 0;
                printf("%d", key[i]);
            }
            else printf(" %d", key[i]);
        }
    }
    
    
    return 0;
}
