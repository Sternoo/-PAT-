//这题通过率低的原因注意点如下：
//1.答案所需的颜色是独一无二的点，除了周围八个元素差值满足条件以外，还要是在数组中不重复出现的数；
//2.该题需要扫描每一个点，包括边界点，因此将数组开大两个长度，边界用0填充。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct postion{
    int x;
    int y;
    int color;
    int count;
}postion;

int main(int argc, const char * argv[]) {
    
    int M, N, TOL;
    scanf("%d %d %d", &M, &N, &TOL);
    
    int **color;
    color = (int **) malloc(sizeof(int *) * (N+2));
    int i = 0;
    for (; i < N + 2; i ++) {
        color[i] = (int *) malloc(sizeof(int) * (M+2));
        int j = 0;
        for (; j < M + 2; j ++) {
            if (i > 0 && i < N + 1 && j > 0 && j < M + 1) {
                scanf("%d", &color[i][j]);
            } else {
                color[i][j] = 0;
            }
        }
    }
    int length = 10;
    int j_count = 0;
    postion *judge = (postion *) malloc(sizeof(postion) * length);
    for (i = 1; i < N + 1; i ++) {
        int j;
        for (j = 1; j < M + 1; j ++) {
            int k;
            for (k = 0; k < j_count; k ++) {
                if (judge[k].color == color[i][j]) {
                    judge[k].count ++;
                    break;
                }
            }
            if (k == j_count) {
                if (j_count >= length) {
                    length += 10;
                    judge = (postion *) realloc(judge, sizeof(postion) * length);
                }
                judge[j_count].x = i;
                judge[j_count].y = j;
                judge[j_count].color = color[i][j];
                judge[j_count].count = 1;
                j_count ++;
            }
        }
    }
    
    int pos_x = 0, pos_y = 0;
    int count = 0;
    for (i = 0; i < j_count; i ++) {
        if (judge[i].count == 1) {
            int m = judge[i].x;
            int n = judge[i].y;
            int temp = color[m][n];
            if (abs(temp - color[m - 1][n - 1]) > TOL && abs(temp - color[m][n - 1]) > TOL && abs(temp - color[m + 1][n - 1]) > TOL
                && abs(temp - color[m - 1][n]) > TOL && abs(temp - color[m + 1][n]) > TOL
                && abs(temp - color[m + 1][n - 1]) > TOL && abs(temp - color[m + 1][n]) > TOL && abs(temp - color[m + 1][n + 1]) > TOL) {
                count ++;
                if (count > 1) {
                    printf("Not Unique");
                    return 0;
                } else {
                    pos_x = m;
                    pos_y = n;
                }
            }
        }
    }
    
    if (count == 0){
        printf("Not Exist");
    } else {
        printf("(%d, %d): %d", pos_y, pos_x, color[pos_x][pos_y]);
    }
    free(judge);
    free(color);
    return 0;
}
