#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char num[1001];
    int div;
    scanf("%s %d", num, &div);
    int i = 0;
    int res_pos = 0;
    int res[1001];
    int left = 0;
    for (; num[i] != '\0'; i ++) {
        int temp = num[i] - '0';
        res[i] = (left * 10 + temp) / div;
        left = (left * 10 + temp) % div;
        res_pos ++;
    }
    
    int j = 0;
    int flag = 1;
    for (; j < res_pos; j ++) {
        if (res[j] == 0 && flag) {
            continue;
        }
        flag = 0;
        printf("%d", res[j]);
    }
    if (flag) {
        printf("0");
    }
    printf(" %d", left);
    return 0;
}
