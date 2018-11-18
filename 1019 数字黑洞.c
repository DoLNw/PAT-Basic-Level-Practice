#include <stdio.h>

void sort(char s[5]) {
    char temp;
    for (int i=0; i<5; i++) {
        for (int j=0; j<i; j++) {
            if (s[i]>s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    printf("Hello World!\n");
    
    char a[5];
    //注意字符串的写入int+48
    scanf("%s", a);
    if (a[1]=='\0') {
        a[1] = 48;
        a[2] = 48;
        a[3] = 48;
    }
    if (a[2]=='\0') {
        a[2] = 48;
        a[3] = 48;
    }
    if (a[3]=='\0') {
        a[3] = 48;
    }
    a[4] = '\0';
    
    int result = 0;
    int aa=0, bb=0;
    
    if (a[0]==a[1] && a[1]==a[2] && a[2]==a[3]) {
        result = 6174;
        printf("%s - %s = 0000\n", a, a);
    }
    
    while (result != 6174) {
        sort(a);
        aa = (a[0]-48)*1000 + (a[1]-48)*100 + (a[2]-48)*10 + (a[3]-48);
        bb = (a[3]-48)*1000 + (a[2]-48)*100 + (a[1]-48)*10 + (a[0]-48);
        result = aa - bb;
        printf("%04d - %04d = %04d\n", aa, bb, result);
        a[0] = result % 10 + 48;
        a[1] = result / 10 % 10 + 48;
        a[2] = result / 100 % 10 + 48;
        a[3] = result / 1000 % 10 + 48;
    }
    
    return 0;
}

