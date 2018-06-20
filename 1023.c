#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int count[10];
    int i = 0;
    for (; i < 10; i ++) {
        scanf("%d", &count[i]);
        getchar();
    }
    
    int flag = 1;
    for (i = 1; i < 10; i ++) {
        int temp = count[i];
        if (temp != 0) {
            int j = 0;
            for (; j < temp; j ++) {
                printf("%d", i);
                if (flag) {
                    int count_zero = count[0];
                    int k = 0;
                    for (; k < count_zero; k ++) {
                        printf("0");
                    }
                    flag = 0;
                }
            }
        }
    }
    
    return 0;
}
