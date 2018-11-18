#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int*)a - *(int*)b;}

int main() {
    printf("Hellow World!\n");
    
    int N, p;
    scanf("%d %d", &N, &p);
    int data[N];
    
    for (int i=0; i<N; i++) {
        scanf("%d", data+i);
    }
    
    qsort(data, N, sizeof(int), compare);
    
    int max = 0;
    for (int first=0, last=0; last<N; first++) {
        while (last<N && data[last] <= 1L * data[first] * p ) last++;
        if (max < last - first) {
            max = last - first;
        }
    }
    
    printf("%d", max);
    
    return 0;
}


