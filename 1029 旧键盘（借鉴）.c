#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Hellow World!\n");
    
    char line[82], c, printed[128] = {0};
    
    //③
    //    //使用gets()
    //    char buffer[4096];
    //    gets(buffer);
    //    //使用fgets()替换gets()
    //    char buffer[4096];
    //    fgets(buffer, (sizeof buffer / sizeof buffer[0]), stdin);
    
    //①
    //    scanf("%s", line);
    //    while((c = getchar()) != '\n') ;
    //    while((c = getchar()) != '\n')
    //    printed[toupper(c)]++;
    
    //②
    //gets函数，可以无限读取，不会判断上限,gets是从stdin流中读取字符串，直至接受到换行符或EOF时停止，并将读取的结果存放在buffer指针所指向的字符数组中。换行符不作为读取串的内容，读取的换行符被转换为null值，并由此来结束字符串，做好用fgets。
    gets(line);
    while ((c = getchar()) != '\n') {
        printed[toupper(c)] = 1;
    }
    
    //'\0'的ascii为0
    for (char *p = line; *p; p++) {
        if (printed[toupper(*p)] == 0) {
            putchar(toupper(*p));
            printed[toupper(*p)] = -1;
        }
    }
    
    return 0;
}


