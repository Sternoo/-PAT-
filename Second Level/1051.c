//精度选取double，注意-0.009这种情况保留小数舍去之后是为-0.00的，
//应当输出的是0.00
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    double R1, P1, R2, P2;
    scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
    double real_part = R1 * R2 * cos(P1 + P2);
    double void_part = R1 * R2 * sin(P1 + P2);
    if (fabs(real_part) < 0.01) {
        printf("0.00");
    } else {
        printf("%.2lf", real_part);
    }
    
    if (void_part >= 0) {
        printf("+%.2lfi", void_part);
    } else if (fabs(void_part) < 0.01) {
        printf("+0.00i");
    } else {
        printf("%.2lfi", void_part);
    }
    
    return 0;
}
