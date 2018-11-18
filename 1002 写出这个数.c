//
//  main.c
//  1002
//
//  Created by JiaCheng on 2018/10/15.
//  Copyright © 2018 JiaCheng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int sum = 0;
    char string[100];
    char sumStr[5];
    
    scanf("%s", string);
    for (int i=0; string[i] != '\0'; i++) {
        sum += string[i]-48;
    }
    sprintf(sumStr,"%d",sum);
    for (int i=0; sumStr[i] != '\0'; i++) {
        if (i==0) {
            switch (sumStr[i]) {
                case '0':
                    printf("ling");
                    break;
                case '1':
                    printf("yi");
                    break;
                case '2':
                    printf("er");
                    break;
                case '3':
                    printf("san");
                    break;
                case '4':
                    printf("si");
                    break;
                case '5':
                    printf("wu");
                    break;
                case '6':
                    printf("liu");
                    break;
                case '7':
                    printf("qi");
                    break;
                case '8':
                    printf("ba");
                    break;
                case '9':
                    printf("jiu");
                    break;
            }
        } else {
            switch (sumStr[i]) {
                case '0':
                    printf(" ling");
                    break;
                case '1':
                    printf(" yi");
                    break;
                case '2':
                    printf(" er");
                    break;
                case '3':
                    printf(" san");
                    break;
                case '4':
                    printf(" si");
                    break;
                case '5':
                    printf(" wu");
                    break;
                case '6':
                    printf(" liu");
                    break;
                case '7':
                    printf(" qi");
                    break;
                case '8':
                    printf(" ba");
                    break;
                case '9':
                    printf(" jiu");
                    break;
            }
        }

    }
//    int n = 0;
//    while (sum != 0) {
//        n = sum%10;
//        sum /= 10;
//        printf("%d\n", n);
//    }
    
    return 0;
}
