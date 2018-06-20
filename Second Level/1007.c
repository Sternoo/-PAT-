#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LISTLENTH 10
#define INCREMENT 10

int main(int argc, const char * argv[]) {
    
    int list_length = 10;
    int *list = malloc(sizeof(int) * list_length);
    int count = 0;
    int N;
    scanf("%d", &N);
    int i = 2;
    for (; i <= N; i ++) {
        if (count >= list_length) {
            list_length += INCREMENT;
            list = realloc(list, sizeof(int) * (list_length));
        }
        int j = 2;
        int flag = 1;
        for (; j <= sqrt(i); j ++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            list[count ++] = i;
        }
    }
    int k = 0;
    int match_count = 0;
    for (; k <count; k ++) {
        if (list[k + 1] - list[k] == 2) {
            match_count ++;
        }
    }
    printf("%d", match_count);
    return 0;
}
