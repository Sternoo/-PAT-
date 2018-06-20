#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int list_count = 10, increment = 10;
    int *list = (int *)malloc(sizeof(int) * list_count);
    int number;
    scanf("%d", &number);
    int *number_list = (int *)malloc(sizeof(int) * number);
    int i;
    int count = 0;
    for (i = 0; i < number; i ++) {
        int figure;
        scanf("%d", &figure);
        number_list[i] = figure;
        while (figure != 1) {
            if (count >= list_count) {
                list_count += increment;
                list = (int *)realloc(list,  sizeof(int) * (list_count));
            }
            if (figure % 2 == 0) {
                figure = figure / 2;
            } else {
                figure = (figure * 3 + 1) / 2;
            }
            int k = 0;
            int flag = 0;
            for (; k < count; k ++) {
                if (list[k] == figure) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                list[count ++] = figure;
            }
        }
    }
    int *res_list = (int *) malloc(sizeof(int) * number);
    int res_count = 0;
    int m = 0;
    for (; m < number; m ++) {
        int n = 0;
        int flag = 0;
        for (; n < count; n ++) {
            if (number_list[m] == list[n]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            res_list[res_count] = number_list[m];
            res_count ++;
        }
    }
    int l1, l2, temp;
    for (l1 = 0; l1 < res_count - 1; l1 ++) {
        for (l2 = 0; l2 < res_count - 1- l1; l2 ++) {
            if (res_list[l2] < res_list[l2 + 1]) {
                temp = res_list[l2];
                res_list[l2] = res_list[l2 + 1];
                res_list[l2 + 1] = temp;
            }
        }
    }
    for (l1 = 0; l1 < res_count; l1 ++) {
        printf("%d", res_list[l1]);
        if (l1 != res_count - 1) {
            printf(" ");
        }
    }
    free(list);
    free(number_list);
    free(res_list);
    return 0;
}
