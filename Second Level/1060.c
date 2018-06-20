#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d",&count);

    int *input = (int *)malloc(sizeof(int) * count);
    int i = 0;
    for (; i < count; i ++) {
        scanf("%d", input + i);
    }
    qsort(input, count, sizeof(int), cmp);
    
    int res = 0;
    int j;
    for (j = 0; j < count; j ++) {
        if (input[j] > count - j) {
            //count-j为排序后第j个后面有多少天加上第j天本身的天数，
            //只要input[j]大于这个天数，那么后面的每一天都大于这个天数，那么count-j就是答案了
            res = count - j;
            break;
        }
    }
    printf("%d", res);
    free(input);
    return 0;
}
