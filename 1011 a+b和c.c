#include <stdio.h>
int main(int argc, const char * argv[]) {
    
    int count;
    long long int a, b, c;
    
    scanf("%d", &count);
    
    for (int i=0; i<count; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: ", i+1);
            printf("true\n");
        } else {
            printf("Case #%d: ", i+1);
            printf("false\n");
        }
    }
    
    
    return 0;
}

