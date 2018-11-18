#include <stdio.h>
#include <string.h>
//貌似一个个右移比我这个都快,好像不行画不能多余数组
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int number, offset, finishedCount = 0, index1 = 0;
    int nums[101];
    
    scanf("%d %d", &number, &offset);
    
    for (int i=0; i<number; i++) {
        scanf("%d", nums+i);
    }
    int temp, saved = nums[0];
    
    while (finishedCount != number) {
        offset %= number;
        if (offset == 0) break;
        if (number%offset==0) {
            if (finishedCount % (number/offset) == 0 && finishedCount != 0) {
                index1 = finishedCount/(number/offset);
                saved = nums[index1];
            }
            index1 += offset;
            if (index1>=number) {
                index1 = finishedCount/(number/offset);
            }
            temp = nums[index1];
            nums[index1] = saved;
            saved = temp;
        } else {
            if ((index1+=offset)>=number) {
                index1 -= number;
            }
            temp = nums[index1];
            nums[index1] = saved;
            saved = temp;
        }
        finishedCount++;
    }
    
    printf("%d", nums[0]);
    for (int i=1; i<number; i++) {
        printf(" %d", nums[i]);
    }
    
    return 0;
}

