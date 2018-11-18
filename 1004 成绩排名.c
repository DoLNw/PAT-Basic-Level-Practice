#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int row;
    //注意：它说不超过10个字符，那你需要11个，因为'\0'.
    char name[11], nameSavedMax[11], id[11], idSavedMax[11], nameSavedMin[11], idSavedMin[11];
    int score, scoreSavedMax=-1, scoreSavedMin=101;
    
    scanf("%d", &row);
    
    while (row--) {
        //一个scanf是读到空格处就不读取了，但是要回车才能结束。
        scanf("%s", name);
        scanf("%s", id);
        scanf("%d", &score);
        if (score > scoreSavedMax) {
            sprintf(nameSavedMax, "%s", name);
            sprintf(idSavedMax, "%s", id);
            scoreSavedMax = score;
        }
        if (score < scoreSavedMin) {
            sprintf(nameSavedMin, "%s", name);
            sprintf(idSavedMin, "%s", id);
            scoreSavedMin = score;
        }
    }
    
    printf("%s %s\n", nameSavedMax, idSavedMax);
    printf("%s %s", nameSavedMin, idSavedMin);
    
    return 0;
}

