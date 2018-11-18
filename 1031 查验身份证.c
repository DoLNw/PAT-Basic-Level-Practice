#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int*)a - *(int*)b;}

int main() {
    printf("Hellow World!\n");
    
    int N;
    char data[19], isAllPass=1;
    scanf("%d", &N);
    
    while (N--) {
        scanf("%s", data);
        
        int i = 0;
        for (i=0; i<17; i++) {
            if (data[i]<='9' && data[i]>='0') continue;
            else break;
        }
        data[18] = '\0';
        if (i!=17) {
            isAllPass = 0;
            printf("%s\n", data);
            continue;
        }
        
        //7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2
        int checkData = (data[0]-48)*7 + (data[1]-48)*9 + (data[2]-48)*10 + (data[3]-48)*5 + (data[4]-48)*8 + (data[5]-48)*4 + (data[6]-48)*2 + (data[7]-48)*1 + (data[8]-48)*6 + (data[9]-48)*3 + (data[10]-48)*7+ (data[11]-48)*9 + (data[12]-48)*10 + (data[13]-48)*5 + (data[14]-48)*8 + (data[15]-48)*4 + (data[16]-48)*2;
        checkData %= 11;
        char c;
        //Z：0 1 2 3 4 5 6 7 8 9 10
        //M：1 0 X 9 8 7 6 5 4 3 2
        switch (checkData) {
            case 0:
                c = 1 + 48;
                break;
            case 1:
                c = 0 + 48;
                break;
            case 2:
                c = 'X';
                break;
            case 3:
                c = 9 + 48;
                break;
            case 4:
                c = 8 + 48;
                break;
            case 5:
                c = 7 + 48;
                break;
            case 6:
                c = 6 + 48;
                break;
            case 7:
                c = 5 + 48;
                break;
            case 8:
                c = 4 + 48;
                break;
            case 9:
                c = 3 + 48;
                break;
            case 10:
                c = 2 + 48;
                break;
            default:
                c = 0;
        }
        //        printf("%c", c);
        
        if (c != data[17]) {
            isAllPass = 0;
            printf("%s\n", data);
        }
    }
    if (isAllPass) {
        printf("All passed");
    }
    
    return 0;
}

