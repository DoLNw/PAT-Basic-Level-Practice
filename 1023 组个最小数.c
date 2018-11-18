#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    char result[50];
    int number[11], j = 0, index = 0;
    
    scanf("%d", &number[0]);
    for (int i=1; i<10; i++) {
        scanf("%d", &number[i]);
        if (number[i] == 0 && index == i-1) {
            index = i;
        }
    }
    if (number[0] != 0 && index != -1) {
        number[index+1]--;
        result[j++] = index+1+48;
    }
    
    for (int i=0; i<10; i++) {
        while (number[i]--) {
            result[j++] = i+48;
        }
    }
    result[j] = '\0';
    
    printf("%s\n", result);
    
    return 0;
}

