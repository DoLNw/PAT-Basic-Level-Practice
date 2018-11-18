#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int canPrint = 0;
    int min, max;
    int count = 0;
    int i = 1;
    
    scanf("%d %d", &min, &max);
    
    int j = 2;
    while (count <= 10000) {
        i++;
        for (j=2; j*j<=i; j++) {
            if (i%j == 0) break;
        }
        if (j*j > i) {
            count++;
            if (count == max+1) {
                break;
            } else if ( count<=max && count >=min) {
                canPrint++;
            }
            if (canPrint) {
                switch (canPrint%10) {
                    case 1:
                        printf("%d", i);
                        break;
                    case 0:
                        //它说但行末不得有多余空格，没有说不能由多余的换行，所以不用处理。
                        printf(" %d\n", i);
                        break;
                    default:
                        printf(" %d", i);
                        break;
                }
            }
            
        }
    }
    
    return 0;
}
