#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int row, number;
    int a1=0, a2=0, a3=0, a5=0, a4 = 0;
    //我去，一直出错的原因是居然数组没有初始化啊现在全部初始化的方法也知道了，而且这里有1000h个数，要计数的话可能用char类型不够。
    //注意一定要的啊,一定,因为这个编译器可能不初始化默认都是0，然后别的编译器不一定的好吗？
    int i[5] = {0};
    
    scanf("%d", &row);
    
    while (row--) {
        scanf("%d", &number);
        
        switch (number%5) {
            case 0:
                //直接取余10即可
                if (number%2==0) {
                    i[0] = 1;
                    a1 += number;
                }
                break;
            case 1:
                //正负1乘以number即可
                //A2可能会等于0！直接用A2来判断输出可能会有部分答案是错的
                if (i[1] == 0) {
                    i[1] = 1;
                    a2 = number;
                } else if (i[1] == 1) {
                    a2 -= number;
                    i[1] = 2;
                } else {
                    a2 += number;
                    i[1] = 1;
                }
                break;
            case 2:
                i[2] = 1;
                a3++;
                break;
            case 3:
                i[3] ++;
                a4 += number;
                break;
            case 4:
                i[4] = 1;
                if (number > a5) {
                    a5 = number;
                }
        }
    }
    
    if (i[0] != 0) printf("%d ", a1); else printf("N ");
    if (i[1] != 0) printf("%d ", a2); else printf("N ");
    if (i[2] != 0) printf("%d ", a3); else printf("N ");
    if (i[3] != 0) printf("%0.1f ", (a4*1.0)/i[3]); else printf("N ");
    if (i[4] != 0) printf("%d\n", a5); else printf("N");
    
    return 0;
}

