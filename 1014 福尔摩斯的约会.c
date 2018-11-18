#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char a[100], b[100], c[100], d[100];
    char saved[5] = { 0 };
    
    scanf("%s %s %s %s", a, b, c, d);
    
    for (int i=0; a[i]!='\0' && b[i]!='\0'; i++) {
        if (a[i] == b[i]) {
            if (saved[0] == 0 && (a[i]<='G' && a[i]>='A')) {
                saved[0] = a[i];
            } else if (saved[0]!=0 && saved[1]==0 && ((a[i]<='N' && a[i]>='A') || (a[i]<='9' && a[i]>='0'))) {
                saved[1] = a[i];
                break;
            }
        }
    }
    
    int j;
    for (j=0; c[j]!='\0' && d[j]!='\0'; j++) {
        if (c[j] == d[j] && ((c[j]<='Z' && c[j]>='A') || (c[j]<='z' && c[j]>='a'))) {
            break;
        }
    }
    switch (saved[0] - 64) {
        case 1:
            printf("MON ");
            break;
        case 2:
            //woc
            //之前打成了TUS
            printf("TUE ");
            break;
        case 3:
            printf("WED ");
            break;
        case 4:
            printf("THU ");
            break;
        case 5:
            printf("FRI ");
            break;
        case 6:
            printf("SAT ");
            break;
        case 7:
            printf("SUN ");
            break;
    }
    //小时或者分钟不满足两位的要记得补零,还有上面不一定是A到Z的
    if ((saved[1]-48) >= 17) {
        printf("%d:", saved[1]-55);
    } else {
        printf("%02d:", saved[1]-48);
    }
    
    //    if (j<10) {
    //        //注意输出格式，2前面加个0就是补0，否则空格
    //        printf("%02d", j);
    //    } else {
    //        printf("%d", j);
    //    }
    printf("%02d", j);
    
    return 0;
}


