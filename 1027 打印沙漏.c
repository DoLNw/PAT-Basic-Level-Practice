#include <stdio.h>
#include <math.h>

int main() {
    printf("Hellow World!\n");
    //据运算，总数为2n^-1，行数为2n-1
    int n; char symbol;
    
    scanf("%d %c", &n, &symbol);
    
    int row = (int)sqrt((n+1)/2.0);
    for (int i=row; i>=1; i--) {
        for (int j=0; j<row-i; j++) {
            printf(" ");
        }
        for (int j=1; j<=i*2-1; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    for (int i=2; i<=row; i++) {
        for (int j=0; j<row-i; j++) {
            printf(" ");
        }
        for (int j=1; j<=i*2-1; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    
    printf("%d", n-(2*row*row-1));
    
    return 0;
}


