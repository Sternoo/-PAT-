#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char PA, PB;
    char A[10];
    char B[10];
    int count_a = 0, count_b = 0;
    scanf("%s %c %s %c", A, &PA, B, &PB);
    int i = 0;
    for (; A[i] != '\0'; i ++) {
        if (A[i] == PA) {
            count_a ++;
        }
    }
    i = 0;
    for (; B[i] != '\0'; i ++) {
        if (B[i] == PB) {
            count_b ++;
        }
    }
    
    int res_a = 0;
    int j = 0;
    for (; j < count_a; j ++) {
        res_a = res_a * 10 + (PA - '0');
    }
    int res_b = 0;
    j = 0;
    for (; j < count_b; j ++) {
        res_b = res_b * 10 + (PB - '0');
    }
    printf("%d", res_a + res_b);
    
    return 0;
}
