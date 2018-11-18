#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Hellow World!\n");
    
    char c;
    int ch[128] = { 0 };
    
    while ((c = getchar()) != '\n') {
        ch[toupper(c)] = 1;
    }
    
    while ((c = getchar()) != '\n') {
        //        putchar(c);
        if (!ch[toupper(c)] && !(isupper(c) && ch['+'])) {
            putchar(c);
        }
    }
    printf("\n");
    
    return 0;
}


