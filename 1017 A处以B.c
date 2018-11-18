#include <stdio.h>

int main() {
    printf("Hello World!\n");
    
    //这里整数是1000以内，貌似只能用数组？
    //存储的商可以直接打印不用存储或者存储在int数组也可以的呀。
    char dividend[1001], consult[1001];
    int divisor, consultCount=0;
    
    scanf("%s %d", dividend, &divisor);
    
    int temp = dividend[0] - '0', temp1;
    char index = 0;
    for (int i=1; dividend[i] != '\0'; i++) {
        temp1 = temp / divisor;
        //注意一下int与char的转换
        if (temp1 != 0 || index) {
            index = 1;
            consult[consultCount++] = (char)(temp1 + '0');
        }
        temp = (temp%divisor)*10 + dividend[i]-'0';
    }
    temp1 = temp / divisor;
    int remainder = temp % divisor;
    //注意一下int与char的转换
    consult[consultCount++] = (char)(temp1 + '0');
    //哇，Xcode不加下面这句都是对的，但是这句话一定要加。
    consult[consultCount++] = '\0';
    
    printf("%s %d", consult, remainder);
    
    return 0;
}

