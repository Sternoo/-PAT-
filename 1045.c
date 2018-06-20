//1.第二个测试点：当主元个数为零时，第二行输出空行；
//2.比较的话，先把输入数组排序（升序）一遍，如果元素
//  排序前后的位置不变，那它可能是主元，再通过与原数组
//  左侧最大值进行比较，大于最大值即是主元（右侧不用比较，
//  因为如果元素经过排序位置不变的话，右侧的数一定大于该元素）
#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {

    int count;
    scanf("%d",&count);
    if (count == 0) {
        printf("0");
        return 0;
    }
    int *input = (int *)malloc(sizeof(int) * count);
    int *res = (int *)malloc(sizeof(int) * count);
    int i = 0;
    for (; i < count; i ++) {
        scanf("%d", input + i);
        res[i] = input[i];
    }
    qsort(res, count, sizeof(int), cmp);
    
    int j = 0;
    int t_count = 0;
    int list_count = 10;
    int *left = (int *)malloc(sizeof(int) * list_count);
    int max = 0;
    for (; j < count; j ++) {
        if (input[j] == res[j] && res[j] > max) {
            if (t_count >= list_count) {
                list_count += 10;
                left = realloc(left, sizeof(int) * list_count);
            }
            left[t_count ++] = res[j];
        }
        if (input[j] > max) {
            max = input[j];
        }
    }
    printf("%d\n", t_count);
    if (t_count > 0) {
        int k = 0;
        for (; k < t_count; k ++) {
            printf("%d", left[k]);
            if (k < t_count - 1) {
                printf(" ");
            }
        }
    }
    printf("\n");
    
    return 0;
}
