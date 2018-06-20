//计算过程中int可能溢出，要用long long int
#include <stdio.h>

long long int max_div(long long int a, long long int b) {
    return b == 0 ? a : max_div(b, a % b);
}

void print_result(long long int a, long long int b) {
    long long int z, la, r_flag = 0;
    if (a == 0)
        printf("0");
    else {
        if (a < 0) {
            a = -a;
            r_flag = 1;
        }
        if (r_flag) {
            printf("(-");
        }
        z = a / b;
        la = a % b;
        long long int div = max_div(la, b);
        la /= div;
        b /= div;
        if (z == 0) {
            if (la == 0) {
                printf("0");
            } else {
                printf("%lld/%lld", la, b);
            }
        } else {
            if (la == 0) {
                printf("%lld", z);
            } else {
                printf("%lld %lld/%lld", z, la, b);
            }
        }
        if (r_flag) {
            printf(")");
        }
    }
}

int main(int argc, const char * argv[]) {
    
    long long int a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    
    int i;
    long long int ra = 0, rb = 0;
    for (i = 0; i < 4; i ++) {
        print_result(a1, b1);
        switch (i) {
            case 0: printf(" + "); break;
            case 1: printf(" - "); break;
            case 2: printf(" * "); break;
            case 3: printf(" / "); break;
        }
        print_result(a2, b2);
        printf(" = ");
        
        switch (i) {
            case 0:
                ra = a1 * b2 + a2 * b1;
                rb = b1 * b2;
                print_result(ra, rb);
                break;
            case 1:
                ra = a1 * b2 - a2 * b1;
                rb = b1 * b2;
                print_result(ra, rb);
                break;
            case 2:
                if (a2 == 0) {
                    printf("0");
                } else {
                    ra = a1 * a2;
                    rb = b1 * b2;
                    print_result(ra, rb);
                }
                break;
            case 3:
                if (a2 == 0) {
                    printf("Inf");
                } else {
                    ra = a1 * b2;
                    rb = a2 * b1;
                    if (rb < 0) {
                        ra = -ra;
                        rb = -rb;
                    }
                    print_result(ra, rb);
                }
                break;
        }
        printf("\n");
    }
    
    return 0;
}
