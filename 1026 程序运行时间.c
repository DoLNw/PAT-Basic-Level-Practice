#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    long int C1, C2;
    
    scanf("%ld %ld", &C1, &C2);
    long int sum = (C2 - C1)/100;
    if ((C2-C1) % 100 >= 50) {
        sum++;
    }
    long int h = sum / 3600;
    sum %= 3600;
    long int minute = sum / 60;
    sum %= 60;
    printf("%02ld:%02ld:%02ld", h, minute, sum);
    
    return 0;
}


