#include <stdio.h>

int main() {
    int counts[10] = { 0 };
    char number[1001];
    
    scanf("%s", number);
    
    for (int i=0; number[i] != '\0'; i++) {
        counts[number[i] - 48]++;
    }
    
    for (int i=0; i<10; i++) {
        if (counts[i] != 0) {
            printf("%d:%d\n", i, counts[i]);
        }
    }
    
    return 0;
}

