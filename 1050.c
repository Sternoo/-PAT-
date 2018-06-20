#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void * a, const void * b) {
    return *(int *)b - *(int *)a;
}

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    if (count == 0) {
        return 0;
    }
    int M = count, N = 1, dif = M - N;
    int i;
    for (i = 1; i <= sqrt(count); i ++) {
        if (count % i == 0) {
            int temp = count / i;
            if (temp - i < dif) {
                N = i;
                M = temp;
                dif = M - N;
            }
        }
    }
    
    int *res = (int *)malloc(sizeof(int) * count);
    for (i = 0; i < count; i ++) {
        scanf("%d", &res[i]);
    }
    qsort(res, count, sizeof(int), cmp);
    
    int **a = (int **)malloc(sizeof(int *) * count);
    for (i = 0; i < M; i ++) {
        a[i] = (int *)malloc(sizeof(int) * N);
    }
    
    int left = 0, right = N, top = 0, bottom = M;
    int pos = 0;
    int dir = 0;
    while (count) {
        int m, n;
        switch (dir) {
            case 0:
                n = top;
                for (m = left; m < right; m ++) {
                    a[n][m] = res[pos ++];
                    count --;
                }
                top ++;
                break;
            case 1:
                m = right - 1;
                for (n = top; n < bottom; n ++) {
                    a[n][m] = res[pos ++];
                    count --;
                }
                right --;
                break;
            case 2:
                n = bottom - 1;
                for (m = right - 1; m >= left; m --) {
                    a[n][m] = res[pos ++];
                    count --;
                }
                bottom --;
                break;
            case 3:
                m = left;
                for (n = bottom - 1; n >= top; n --) {
                    a[n][m] = res[pos ++];
                    count --;
                }
                left ++;
                break;
        }
        if (dir == 3) {
            dir = 0;
        } else {
            dir ++;
        }
    }
    for (i = 0; i < M; i ++) {
        int j = 0;
        for (; j < N; j ++) {
            printf("%d", a[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        if (i < M - 1) {
            printf("\n");
        }
    }
    
    return 0;
}
