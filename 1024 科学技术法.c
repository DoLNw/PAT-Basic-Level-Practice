#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    char number[9999*8];
    int index = 0, symbolIndex = 0, exponent = 0;
    
    //注意这样读取还读取到了一个\n
    while (scanf("%c", &number[index]) != EOF) {
        if (number[index] == '+' || number[index] == '-')
            symbolIndex = index;
        if (number[index] == '\n') {
            break;
        }
        index++;
    }
    
    //下面这段代码也对，从下面这段代码也对证明它x也是先加个换行在ctr+D来EOF停止的。
    //    //注意这样读取还读取到了一个\n
    //    while (scanf("%c", &number[index]) != EOF) {
    //        if (number[index] == '+' || number[index] == '-')
    //            symbolIndex = index;
    //        // if (number[index] == '\n') {
    //        //     break;
    //        // }
    //        index++;
    //    }
    //    index--;
    //
    
    for (int i=symbolIndex+1; i<index; i++) {
        exponent =  (exponent * 10) + number[i] - 48;
    }
    
    if (number[0] == '-') {
        printf("-");
    }
    if (number[symbolIndex] == '-') {
        printf("0.");
        for (int i=0; i<exponent-1; i++)
            printf("0");
        printf("%c", number[1]);
        for (int i=3; i<symbolIndex-1; i++) {
            printf("%c", number[i]);
        }
    } else if (number[symbolIndex] == '+') {
        printf("%c", number[1]);
        for (int i=3; i<3+exponent; i++) {
            if (i >= symbolIndex-1) {
                printf("0");
            } else {
                printf("%c", number[i]);
            }
        }
        if (3+exponent >= symbolIndex-1) {
            return 0;
        } else {
            printf(".");
            for (int i=3+exponent; i<symbolIndex-1; i++) {
                printf("%c", number[i]);
            }
        }
    }
    
    
    return 0;
}

