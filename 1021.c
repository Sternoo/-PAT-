#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char num[1001];
    scanf("%s", num);
    int i = 0;
    int res[10] = {0};
    for (; num[i] != '\0'; i ++) {
        int temp = num[i] - '0';
        res[temp] ++;
    }
    int j = 0;
    for (; j < 10; j ++) {
        if (res[j] != 0) {
            printf("%d:%d\n", j, res[j]);
        }
    }
    
    return 0;
}
