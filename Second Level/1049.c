//注释的算法是超时的
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    int i = 0;
    int list_length = 10;
    int pos = 0;
    double *input = malloc(sizeof(double) * list_length);
    for (; i < count; i ++) {
        if (pos >= list_length) {
            list_length += 10;
            input = realloc(input, sizeof(double) * list_length);
        }
        double temp;
        scanf("%lf", &temp);
        input[pos ++] = temp;
    }
    
//    double res = 0;
//    int j = 0;
//    for (; j < pos; j ++) {
//        int k = j;
//        double sum = 0;
//        for (; k < pos; k ++) {
//            sum += input[k];
//            res += sum;
//        }
//    }
    double res = 0;
    int j = 0;
    for (; j < pos; j ++) {
        res += input[j] * (count - j) * (j + 1);
    }
    printf("%.2lf", res);
    
    return 0;
}
