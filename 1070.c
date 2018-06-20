#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    int *rops = (int *)malloc(sizeof(int) * count);
    int i = 0;
    for (; i < count; i ++) {
        int temp;
        scanf("%d", &temp);
        rops[i] = temp;
    }
    qsort(rops, count, sizeof(int), cmp);
    double sum = (rops[0] + rops[1]) * 1.0 / 2;
    int j = 2;
    for (; j < count; j ++) {
        sum = (sum + rops[j]) / 2;
    }
    printf("%d", (int)sum);
    
    return 0;
}
