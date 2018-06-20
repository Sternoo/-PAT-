#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int N, D;
    double e;
    scanf("%d %lf %d", &N, &e, &D);
    
    int i = 0;
    int maybe_vacant = 0;
    int vacant = 0;
    for (; i < N; i ++) {
        int K;
        scanf("%d", &K);
        int j = 0;
        int count_day = 0;
        for (; j < K; j ++) {
            double temp;
            scanf("%lf", &temp);
            if (temp < e) {
                count_day ++;
            }
        }
        if (count_day > K/2) {
            if (K > D) {
                vacant ++;
            } else {
                maybe_vacant ++;
            }
        }
    }
    printf("%.1lf%% %.1lf%%", maybe_vacant * 100.0 / N, vacant * 100.0 / N);
    
    return 0;
}
