//用double会失真，要用分子分母相乘比较。
//例:如果n1/m1 < n2/m2,那么 n1*m2 < n2*m1
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    
    int list_length = 10;
    int *res = (int *)malloc(sizeof(int) * list_length);
    int count = 0;
    
    if (n1 * m2 > n2 * m1) {
        int temp1 = n1;
        n1 = n2;
        n2 = temp1;
        
        int temp2 = m1;
        m1 = m2;
        m2 = temp2;
    }
    
    int i = 1;
    for (; i < k; i ++) {
        if (i * m1 <= k * n1) {
            continue;
        } else if (i * m2 >= k * n2) {
            break;
        }
        int j = 2;
        int flag = 1;
        for (; j <= i; j ++) {
            if (i % j == 0 && k % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (count >= list_length) {
                list_length += 10;
                res = (int *)realloc(res, sizeof(int) * list_length);
            }
            res[count ++] = i;
        }
    }
    for (i = 0; i < count; i ++) {
        printf("%d/%d", res[i], k);
        if (i < count - 1) {
            printf(" ");
        }
    }
    free(res);
    
    return 0;
}
