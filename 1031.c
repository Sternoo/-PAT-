#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int number;
    scanf("%d", &number);
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char verify[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2', '\0'};
    int i = 0;
    int flag = 1;
    for (; i < number; i ++) {
        char identity[19];
        scanf("%s", identity);
        int j = 0;
        int sum = 0;
        for (; j < 17; j ++) {
            if (identity[j] <= '9' && identity[j] >= '0') {
                int temp = identity[j] - '0';
                sum += temp * weight[j];
            } else {
                flag = 0;
                printf("%s\n", identity);
                break;
            }
        }
        if (j == 17) {
            sum %= 11;
            if (verify[sum] != identity[17]) {
                flag = 0;
                printf("%s\n", identity);
            }
        }
    }
    if (flag) {
        printf("All passed");
    }
    
    return 0;
}
