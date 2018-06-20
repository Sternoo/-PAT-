//注意6173测试点
#include <stdio.h>

int Kaprekar(int num) {
    int result[4] = {0};
    int i;
    for (i = 3; i >= 0; i --) {
        result[i] = num % 10;
        num = num / 10;
        if (num == 0) {
            break;
        }
    }
    int j = 0;
    for (; j < 3; j ++) {
        int k = 0;
        int temp = 0;
        for (; k < 3 - j; k ++) {
            if (result[k] < result[k + 1]) {
                temp = result[k];
                result[k] = result[k + 1];
                result[k+ 1] = temp;
            }
        }
    }
    int res_a[4], res_b[4];
    int l = 0;
    int pos = 3;
    for (; l < 4; l ++) {
        res_a[l] = result[l];
        res_b[l] = result[pos --];
        printf("%d", result[l]);
    }
    printf(" - ");
    int m = 0;
    for (; m < 4; m ++) {
        printf("%d", res_b[m]);
    }
    printf(" = ");
    int res = (res_a[0] - res_b[0]) * 1000 + (res_a[1] - res_b[1]) * 100 + (res_a[2] - res_b[2]) * 10 + (res_a[3] - res_b[3]);
    printf("%04d\n", res);
    return res;
}

int main(int argc, const char * argv[]) {
    
    int N;
    scanf("%d", &N);
    do {
        N = Kaprekar(N);
        if (N == 0) {
            break;
        }
    } while (N != 6174);
    
    return 0;
}
