//
//  main.c
//  1003 我要通过
//
//  Created by JiaCheng on 2018/10/15.
//  Copyright © 2018 JiaCheng. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char str[100];
    int row = 0;
    
    scanf("%d", &row);
    while (row--) {
        scanf("%s", str);
        
        int formerCount = 0, latterCount = 0, middleCount = 0;
        int valid = 0;
        int i = 0;
        for (i=i; str[i]!='P'; i++) {
            if (str[i]=='A') formerCount++;
            else valid = 1;
        }
        i++;
        for (i=i; str[i]!='T'; i++) {
            if (str[i]=='A') middleCount++;
            else valid = 1;
        }
        i++;
        for (i=i; str[i]!='\0'; i++) {
            if (str[i]=='A') latterCount++;
            else valid = 1;
        }
        if (middleCount==0) valid = 1;
        if (formerCount*middleCount != latterCount) valid = 1;
        if (!valid) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
