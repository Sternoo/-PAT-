#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    int i = 0;
    int list_length = 10;
    int pos = 0;
    int *res = malloc(sizeof(double) * list_length);
    for (; i < count; i ++) {
        char temp[5];
        scanf("%s", temp);
        int j = 0;
        int sum = 0;
        for (; temp[j] != '\0'; j ++) {
            sum += temp[j] - '0';
        }
        int k = 0;
        for (; k < pos; k ++) {
            if (res[k] == sum) {
                break;
            }
        }
        if (k == pos) {
            if (pos >= list_length) {
                list_length += 10;
                res = realloc(res, sizeof(double) * list_length);
            }
            res[pos ++] = sum;
        }
    }
    qsort(res, pos, sizeof(int), cmp);
    printf("%d\n", pos);
    int o = 0;
    for (; o < pos; o ++) {
        printf("%d", res[o]);
        if (o < pos - 1) {
            printf(" ");
        }
    }
    
    return 0;
}
