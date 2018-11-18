#include <stdio.h>
#include <string.h>
//貌似一个个右移比我这个都快,好像不行画不能多余数组
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char str[81][81];
    int i=0;
    while (scanf("%s", str[i])!= EOF) {
        i++;
    }
    
    for (i=i-1; i>=1; i--) {
        printf("%s ", str[i]);
    }
    printf("%s", str[0]);
    
    return 0;
}

