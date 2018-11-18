#include <stdio.h>
#include <string.h>
//貌似一个个右移比我这个都快,好像不行画不能多余数组
int main(int argc, const char * argv[]) {
    // insert code here...
    char ch ;
    char flag = 1;
    char isFirst = 0;
    int former = 0, latter = 0;
    scanf("%d", &former);
    while (scanf("%c", &ch)!= EOF) {
        if (ch == ' ') {
            if (isFirst) {
                scanf("%d", &former);
                isFirst = 0;
            } else {
                scanf("%d", &latter);
                isFirst = 1;
                if (latter == 0) {
                    continue;
                } else {
                    former *= latter;
                    latter -= 1;
                    if (flag) {
                        flag = 0;
                        printf("%d %d", former, latter);
                    } else {
                        printf(" %d %d", former, latter);
                    }
                }
            }
        }
    }
    
    if (flag) {
        printf("0 0");
    }
    
    return 0;
}

