#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello World!\n");
    
    int num;
    int count = 0;
    
    scanf("%d", &num);
    
    //素数对，13，57这样算，35就不算了它们。
    //擦，上面是算的，我之前把1y也当作素数了，🤦‍♂️
    int primeNum = 2, j=0;
    count = 0;
    
    for (int i=3; i<=num; i++) {
        for (j=2; j*j<=i; j++) {
            if (i%j == 0) break;
        }
        if (j*j > i) {
            if (i - primeNum == 2) {
                count++;
            }
            primeNum = i;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
