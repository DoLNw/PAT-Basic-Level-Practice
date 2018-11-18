#include <stdio.h>

int main() {
    printf("Hello World!\n");
    //本来记胜利手势的次数用字典不错。
    int n, aCount[4] = {0}, bCount[4] = {0};
    char a[2],b[2];
    int aWin=0, aTie=0, aFail=0;
    
    scanf("%d", &n);
    
    while (n--) {
        //读取字符的话，会把换行，空格这些读取进来。
        //读取整数的话好像也有点问题，我现在不清楚。
        scanf("%s %s", a, b);
        if (a[0]-b[0]=='B'-'C') { aWin++; aCount[0]++;}
        else if (a[0]-b[0]=='B'-'J') { aFail++; bCount[2]++;}
        else if (a[0]-b[0]=='C'-'B') { aFail++; bCount[0]++;}
        else if (a[0]-b[0]=='C'-'J') { aWin++;  aCount[1]++;}
        else if (a[0]-b[0]=='J'-'B') { aWin++;  aCount[2]++;}
        else if (a[0]-b[0]=='J'-'C') { aFail++; bCount[1]++;}
        else if (a[0] == 'B') { aTie++;}
        else if (a[0] == 'C') { aTie++;}
        else if (a[0] == 'J') { aTie++;}
    }
    
    printf("%d %d %d\n", aWin, aTie, aFail);
    printf("%d %d %d\n", aFail, aTie, aWin);
    
    int temp = 0;
    for (int i=1; i<3; i++) {
        if (aCount[temp] < aCount[i]) {
            temp = i;
        }
    }
    char temporary[3] = { 'B', 'C', 'J' };
    printf("%c ", temporary[temp]);
    temp = 0;
    for (int i=1; i<3; i++) {
        if (bCount[temp] < bCount[i]) {
            temp = i;
        }
    }
    printf("%c", temporary[temp]);
    
    return 0;
}

