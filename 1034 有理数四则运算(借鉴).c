#include <stdio.h>

long calcgcd(long numerator, long dominator) {
    long r;
    //关于0:任意整数和0的公约数是该整数的所有约数；它们的最大公约数为该整数本身；因为0被所有非0整数整除,所以任意非零的整数都是0的约数
    //还有因为0不会在分母只在分子所以不用额外判断分母为0的情况
    while ((r = numerator % dominator)) {
        numerator = dominator;
        dominator = r;
    }
    
    return dominator;
}

void printfrac(long numerator, long dominator) {
    if (dominator == 0) { printf("Inf"); return; }
    
    char positive = 1;
    if (numerator < 0) { numerator = -numerator; positive *= -1; }
    if (dominator < 0) { dominator = -dominator; positive *= -1; }
    
    long gcd = calcgcd(numerator, dominator);
    numerator /= gcd;
    dominator /= gcd;
    
    if (positive == -1) { printf("(-"); }
    if (numerator/dominator && numerator%dominator) { printf("%ld %ld/%ld", numerator/dominator, numerator%dominator, dominator); }
    else if (numerator%dominator) { printf("%ld/%ld", numerator%dominator, dominator); }
    else { printf("%ld", numerator/dominator); }
    if (positive == -1) { printf(")");  }
}

int main() {
    printf("Hellow World!\n");
    
    long a1, a2, b1, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    
    char op[4] = {'+', '-', '*', '/'};
    for (int i=0; i<4; i++) {
        printfrac(a1, b1); printf(" %c ", op[i]);
        printfrac(a2, b2); printf(" = ");
        
        switch (op[i]) {
            case '+':
                printfrac(a1*b2+a2*b1, b1*b2);
                break;
            case '-':
                printfrac(a1*b2-a2*b1, b1*b2);
                break;
            case '*':
                printfrac(a1*a2, b1*b2);
                break;
            case '/':
                printfrac(a1*b2, a2*b1);
                break;
            default:
                break;
        }
        printf("\n");
    }
    
    return 0;
}



