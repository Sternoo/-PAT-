#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int m, n, s;
    scanf("%d %d %d", &m, &n, &s);
    int list_length = 10;
    char **res = (char **) malloc(sizeof(char *) * list_length);
    int count = 0;
    int i = 0;
    int t_count = 0;
    int flag = 1;
    for (; i < m; i ++) {
        char *temp = (char *) malloc(sizeof(char) * 21);
        scanf("%s", temp);
        t_count ++;
        if (flag) {
            if (t_count < s) {
                free(temp);
                temp = NULL;
                continue;
            } else {
                flag = 0;
            }
        } else {
            if (t_count < n) {
                free(temp);
                temp = NULL;
                continue;
            }
        }
        int j = 0;
        for (; j < count; j ++) {
            if (strcmp(res[j], temp) == 0) {
                break;
            }
        }
        if (j == count) {
            if (count >= list_length) {
                list_length += 10;
                res = (char **)realloc(res, sizeof(char *) * list_length);
            }
            res[count] = malloc(sizeof(char) * 21);
            res[count ++] = temp;
            t_count = 0;
        }
    }
    if (count == 0) {
        printf("Keep going...");
    } else {
        int k = 0;
        for (; k < count; k ++) {
            printf("%s", res[k]);
            if (k < count - 1) {
                printf("\n");
            }
        }
    }
    free(res);
    
    return 0;
}
