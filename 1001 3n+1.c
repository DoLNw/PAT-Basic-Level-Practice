//
//  main.c
//  1001 3n+1
//
//  Created by JiaCheng on 2018/10/15.
//  Copyright © 2018 JiaCheng. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, count = 0;
    scanf("%d",&n);

    while (n != 1) {
        if (n%2 != 0) n = (3*n+1)/2;
        else n /= 2;
        count++;
    }
    
    printf("%d\n",count);
    
    return 0;
}
