#include <stdio.h>

typedef struct {
    //注意：本来为了省内存， 下面就一个是用double的，但是测试点3出错，居然全部改为double就对了。
    double price, number;
    double unitPricr;
}moonCakes;

int main() {
    printf("Hellow World!\n");
    
    int type, number;
    double prices = 0;
    
    scanf("%d", &type);
    if (type != 0) scanf("%d", &number);
    moonCakes cakes[type];
    
    
    for (int i=0; i<type; i++) {
        scanf("%lf", &cakes[i].number);
    }
    for (int i=0; i<type; i++) {
        scanf("%lf", &cakes[i].price);
        cakes[i].unitPricr = cakes[i].price*1.0 / cakes[i].number;
    }
    moonCakes temp;
    for (int i=0; i<type; i++) {
        for (int j=0; j<i; j++) {
            if (cakes[i].unitPricr > cakes[j].unitPricr) {
                temp = cakes[i];
                cakes[i] = cakes[j];
                cakes[j] = temp;
            }
        }
    }
    
    for (int i=0; i<type; i++) {
        if (number >= cakes[i].number) {
            prices += cakes[i].number * cakes[i].unitPricr;
            number -= cakes[i].number;
        } else {
            prices += number * cakes[i].unitPricr;
            number -= number;
        }
        if (number <= 0) {
            break;
        }
    }
    
    printf("%.2lf\n", prices);
    
    return 0;
}

