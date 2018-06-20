//应当把RG=G的情况放于RG>G的分支里，因为放于RG<G里，会造成误判，
//而大于的情况，负数仍然是能输出的
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int S, G, K, RS, RG, RK;
    scanf("%d.%d.%d %d.%d.%d", &G, &S, &K, &RG, &RS, &RK);
    
    int res_k;
    int res_s;
    int res_g;
    int flag;
    if (RG >= G) {
        res_k = RK - K;
        res_s = RS - S;
        res_g = RG - G;
        flag = 0;
    } else {
        res_k = K - RK;
        res_s = S - RS;
        res_g = G - RG;
        flag = 1;
    }
    if (res_k < 0) {
        res_k += 29;
        res_s --;
    }
    if (res_s < 0) {
        res_s += 17;
        res_g --;
    }
    if (flag) {
        printf("-");
    }
    printf("%d.%d.%d", res_g, res_s, res_k);
    
    return 0;
}
