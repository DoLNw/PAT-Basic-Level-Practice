#include <stdio.h>

int main() {
    printf("Hellow World!\n");
    
    int N, num, score;
    scanf("%d", &N);
    //所以int数组初始化没用的,我此处显示只有第一个才是有的，其它的int默认为0，char默认为‘\0’？？？还是我Xcode编译器的问题。
    int totalScore[100000] = { -1 };
    //    char a[3] = {'\0'};
    //    char b[8] = {'c'};
    
    int max = 0;
    while (N--) {
        scanf("%d %d", &num, &score);
        if (totalScore[num-1] == -1) {
            totalScore[num-1] = 0;
        }
        totalScore[num-1] += score;
        if (totalScore[max] < totalScore[num-1]) {
            max = num-1;
        }
    }
    
    printf("%d %d\n", max+1, totalScore[max]);
    
    return 0;
}


