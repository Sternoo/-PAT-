//需优化素数判断方法，如果M不是素数，那么它的因子中
//必有一个引子小于等于根号M，因此只需判断从2到根号M
//没有可以被整除的数即可

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int M, N;
    scanf("%d %d", &M, &N);
    int count = 0;
    int i = 2;
    int lineN = 0;
    while (1) {
        int j;
        int flag = 0;
        for (j = 2; j <= sqrt(i); j ++) {
            if (i % j == 0 && j != i) {
                flag = 1;
                break;
            }
        }
        int temp = i ++;
        if (flag) {
            continue;
        }
        count ++;
        if (count < M) {
            continue;
        } else {
            if (M == N) {
                printf("%d", temp);
                break;
            } else {
                if (count > N) {
                    break;
                } else {
                    if (lineN == 10) {
                        lineN = 0;
                        printf("\n");
                    }
                    printf("%d", temp);
                    lineN ++;
                    if (lineN < 10 && count != N) {
                        printf(" ");
                    }
                }
            }
        }
    }
    return 0;
}
