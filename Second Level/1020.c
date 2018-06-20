//结构体排序
//1.题目中表明需求量是正整数，但是库存和售价是正数，应当用double保存。
//2.当需求大于库存量时应停止计算，即最后for循环的限制，之前不加产生段错误（访问不合法内存）。
#include <stdio.h>
#include <stdlib.h>

typedef struct moon_cake{
    double stock;
    double price;
    double unit_price;
}Moon_cake;

int main(int argc, const char * argv[]) {
    
    int N, D;
    scanf("%d %d", &N, &D);
    if (N == 0 || D == 0) {
        printf("0.00");
        return 0;
    }
    getchar();
    
    Moon_cake *cakes = malloc(sizeof(Moon_cake) * N);
    int i = 0;
    for (; i < 2; i ++) {
        int j = 0;
        for (; j < N; j ++) {
            double temp;
            scanf("%lf", &temp);
            getchar();
            if (i == 0) {
                cakes[j].stock = temp;
            } else {
                cakes[j].price = temp;
            }
        }
    }
    int k = 0;
    for (; k < N; k ++) {
        cakes[k].unit_price = cakes[k].price / cakes[k].stock;
    }
    
    int m = 0;
    for (; m < N; m ++) {
        int n ;
        for (n = m + 1; n < N; n ++) {
            Moon_cake temp;
            if (cakes[m].unit_price < cakes[n].unit_price) {
                temp = cakes[m];
                cakes[m] = cakes[n];
                cakes[n] = temp;
            }
        }
    }
    
    int l = 0;
    double res = 0;
    for (; l < N; l ++) {
        if (D >= cakes[l].stock) {
            res += cakes[l].stock * cakes[l].unit_price;
            D -= cakes[l].stock;
        } else {
            res += D * cakes[l].unit_price;
            break;
        }
    }
    printf("%.2lf", res);
    
    return 0;
}
