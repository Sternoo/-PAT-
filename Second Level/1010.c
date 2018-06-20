//注意输入0 0的情况，直接退循环输出
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int term, exp;
    int flag = 1;
    while (scanf("%d %d", &term, &exp) != EOF) {
        if (exp == 0) {
            break;
        }
        if (flag) {
            flag = 0;
            printf("%d %d", term * exp, exp - 1);
        } else {
            printf(" %d %d", term * exp, exp - 1);
        }
    }
    if (flag == 1) {
        printf("0 0");
    }
    return 0;
}
