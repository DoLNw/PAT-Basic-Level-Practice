//
//  main.c
//  PAT(Basic Level)Practice
//
//  Created by JiaCheng on 2018/10/15.
//  Copyright © 2018 JiaCheng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int num;
    char numStr[5];
    
    scanf("%d", &num);
    //这个函数既可以数字转字符串，也可以用来字符串全体赋值。
    sprintf(numStr, "%d", num);
    
    int count = 0;
    for (int i=0; numStr[i]!='\0'; i++) {
        count++;
    }
    for (int i=0; numStr[i]!='\0'; i++) {
        switch (count) {
            case 1:
                for (int j=0; j<numStr[i]-48; j++) {
                    printf("%d", j+1);
                }
                break;
                
            case 2:
                switch (i) {
                    case 0:
                        for (int j=0; j<numStr[i]-48; j++) {
                            printf("S");
                        }
                        break;
                    case 1:
                        for (int j=0; j<numStr[i]-48; j++) {
                            printf("%d", j+1);
                        }
                        break;
                }
                break;
                
            case 3:
                switch (i) {
                    case 0:
                        for (int j=0; j<numStr[i]-48; j++) {
                            printf("B");
                        }
                        break;
                    case 1:
                        for (int j=0; j<numStr[i]-48; j++) {
                            printf("S");
                        }
                        break;
                    case 2:
                        for (int j=0; j<numStr[i]-48; j++) {
                            printf("%d", j+1);
                        }
                        break;
                }
        }
        
        
    }
    
    return 0;
}

