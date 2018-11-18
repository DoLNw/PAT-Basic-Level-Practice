#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    char a[100], b[100];
    //输出直接%s的话一定要记得数组最后加'\0'。
    char temp[100] = {'\0'};
    char count=0, tempCount=0;
    
    scanf("%s %s", a, b);
    
    for (int i=0; a[i] != '\0'; i++) {
        if (a[i] == b[i-tempCount]) continue;
        else {
            tempCount++;
            int j=0;
            for (j=0; j<count; j++) {
                if (temp[j] == a[i] || (temp[j]+32 == a[i])) break;
            }
            if (j == count) {
                if (a[i]>='a' && a[i]<='z') temp[count++] = a[i]-32;
                else temp[count++] = a[i];
            }
        }
    }
    
    printf("%s\n", temp);
    
    return 0;
}


#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    char a[100], b[100];
    //输出直接%s的话一定要记得数组最后加'\0'。
    char temp[200] = {'\0'};
    char count=0, tempCount=0;
    
    scanf("%s %s", a, b);
    
    for (int i=0; a[i] != '\0'; i++) {
        if (b[i-tempCount] == '\0') {
            int j=0;
            for (j=0; j<count; j++) {
                if (temp[j] == a[i] || (temp[j]+32 == a[i])) break;
            }
            if (j == count) {
                if (a[i]>='a' && a[i]<='z') temp[count++] = a[i]-32;
                else temp[count++] = a[i];
            }
            continue;
        }
        if (a[i] == b[i-tempCount]) continue;
        else {
            tempCount++;
            int j=0;
            for (j=0; j<count; j++) {
                if (temp[j] == a[i] || (temp[j]+32 == a[i])) break;
            }
            if (j == count) {
                if (a[i]>='a' && a[i]<='z') temp[count++] = a[i]-32;
                else temp[count++] = a[i];
            }
        }
    }
    
    temp[count] = '\0';
    printf("%s", temp);
    
    return 0;
}


