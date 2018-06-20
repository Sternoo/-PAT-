#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int number;
    scanf("%d", &number);
    int i = 0;
    int count_a = 0, count_b = 0;
    for (; i < number; i ++) {
        int sa, wa, sb, wb;
        scanf("%d %d %d %d", &sa, &wa, &sb, &wb);
        int temp = sa + sb;
        if (wa != temp) {
            if (wb == temp) {
                count_a ++;
            }
        } else {
            if (wb != temp) {
                count_b ++;
            }
        }
    }
    printf("%d %d", count_a, count_b);
    
    return 0;
}
