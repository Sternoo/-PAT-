//符号后面的空格不用打印，直接换行
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int total;
    char cr;
    scanf("%d %c", &total, &cr);
    if (total == 0) {
        return 0;
    }
    getchar();
    
    int count = 1;
    int line = 1;
    int i = 1;
    int max_temp = 1;
    for (; total >= count + (max_temp + 2) * 2; i ++) {
        count = count + (max_temp + 2) * 2;
        max_temp += 2;
        line += 2;
    }
    int turn_count = line / 2;
    int max_count = 1 + turn_count * 2;
    for (i = 0; i < line; i ++) {
        int cr_count;
        if (i <= turn_count) {
            cr_count = max_count - i * 2;
        } else {
            cr_count = 1 + (i - turn_count) * 2;
        }
        int space_count = (max_count - cr_count) / 2;
        int j = 0;
        for (; j < space_count; j ++) {
            printf(" ");
        }
        int k = 0;
        for (; k < cr_count; k ++) {
            printf("%c", cr);
        }
        printf("\n");
    }
    printf("%d", total - count);
    
    return 0;
}
