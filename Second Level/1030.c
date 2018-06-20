//判断时从后往前超时，从前往后则通过了
#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    
    int N, p;
    scanf("%d %d",&N, &p);
    int *list = (int *)malloc(sizeof(int) * N);
    
    int i = 0;
    for (; i < N; i ++) {
        scanf("%d", &list[i]);
    }
    qsort(list, N, sizeof(int), cmp);
    
    int max = 1;
    int temp = 1;
    for (i = 0; i < N - 1; i ++) {
        int j;
        for (j = i + max; j <= N - 1; j ++) {
            if (list[j] * 1.0 / list[i] <= p) {
                temp = j - i + 1;
                if (temp > max) {
                    max = j - i + 1;
                }
            } else {
                break;
            }
        }
    }
    //    下面是超时的
    //    for (i = 0; i < N - 1; i ++) {
    //        int j;
    //        for (j = N - 1; j >= i + max; j --) {
    //            if (list[j] * 1.0 / list[i] <= p) {
    //                temp = j - i + 1;
    //                if (temp > max) {
    //                    max = j - i + 1;
    //                    break;
    //                }
    //            }
    //        }
    //    }
    printf("%d", max);
    
    return 0;
}
