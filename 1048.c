//B字符串长度小于A时，要在B前端补零
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char A[101], B[101];
    scanf("%s %s", A, B);
    int pos_a = (int)strlen(A);
    int pos_b = (int)strlen(B);
    if (pos_b < pos_a) {
        int i;
        int temp = pos_a - pos_b;
        for (i = 0; i < temp; i ++) {
            int j;
            for (j = pos_b; j >= 1; j --) {
                B[j] = B[j - 1];
            }
            pos_b ++;
            B[0] = '0';
        }
        B[pos_a] = '\0';
        pos_b = pos_a;
    }
    int i;
    for (i = 1; ; i ++) {
        if (pos_a <= 0) {
            break;
        }
        if (i % 2) {
            int temp = (B[pos_b - 1] - '0' + A[pos_a - 1] - '0') % 13;
            if (temp > 9) {
                switch (temp) {
                    case 10:
                        temp = 'J';
                        break;
                    case 11:
                        temp = 'Q';
                        break;
                    case 12:
                        temp = 'K';
                        break;
                }
            } else {
                temp += '0';
            }
            B[pos_b - 1] = temp;
        } else {
            int temp = B[pos_b - 1] - '0' - (A[pos_a - 1] - '0');
            if (temp < 0) {
                temp += 10;
            }
            B[pos_b - 1] = temp + '0';
        }
        pos_a --;
        pos_b --;
    }
    printf("%s", B);
    
    return 0;
}
