#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int numer;
    char c;
    scanf("%d", &numer);
    getchar();
    scanf("%c", &c);
    int line_num = numer * 1.0 / 2 + 0.5;
    int i = 0;
    for (; i < line_num; i ++) {
        if (i == 0 || i == line_num - 1) {
            int j = 0;
            for (; j < numer; j ++) {
                printf("%c", c);
            }
            if (i == 0) {
                printf("\n");
            }
            
        } else {
            int j = 0;
            for (; j < numer; j ++) {
                if (j == 0) {
                    printf("%c", c);
                } else if (j == numer - 1) {
                    printf("%c\n", c);
                } else {
                    printf(" ");
                }
            }
        }
    }
    return 0;
}
