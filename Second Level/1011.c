//输入值运算可能超过int范围
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int number;
    scanf("%d", &number);
    int i;
    for (i = 0; i < number; i ++) {
        int flag = 0;
        long long int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a + b > c) {
            flag = 1;
        }
        if (flag) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    
    return 0;
}
