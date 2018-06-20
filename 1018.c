//其实乙的结果就是甲的结果的倒序
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int num;
    scanf("%d", &num);
    int i = 0;
    int class_a[3] = {0};
    int win_a[3] = {0};
    int win_b[3] = {0};
    for (; i < num; i ++) {
        char temp_a, temp_b;
        getchar();
        scanf("%c", &temp_a);
        getchar();
        scanf("%c", &temp_b);
        if (temp_a == temp_b) {
            class_a[1] ++;
        } else {
            if (temp_a == 'C') {
                if (temp_b == 'J') {
                    class_a[0] ++;
                    win_a[1] ++;
                } else {
                    class_a[2] ++;
                    win_b[0]++;
                }
            } else if(temp_a == 'J') {
                if (temp_b == 'C') {
                    class_a[2] ++;
                    win_b[1] ++;
                } else {
                    class_a[0] ++;
                    win_a[2] ++;
                }
            } else if(temp_a == 'B') {
                if (temp_b == 'J') {
                    class_a[2] ++;
                    win_b[2] ++;
                } else {
                    class_a[0] ++;
                    win_a[0] ++;
                }
            }
        }
    }
    
    printf("%d %d %d\n%d %d %d\n", class_a[0], class_a[1], class_a[2], class_a[2], class_a[1], class_a[0]);
    int max_pos_a = 0, max_pos_b = 0;
    int j = 0;
    for (; j < 3; j ++) {
        if (win_a[max_pos_a] < win_a[j]) {
            max_pos_a = j;
        }
        if (win_b[max_pos_b] < win_b[j]) {
            max_pos_b = j;
        }
    }
    switch (max_pos_a) {
        case 0:
            printf("B");
            break;
        case 1:
            printf("C");
            break;
        case 2:
            printf("J");
            break;
    }
    
    switch (max_pos_b) {
        case 0:
            printf(" B");
            break;
        case 1:
            printf(" C");
            break;
        case 2:
            printf(" J");
            break;
    }
    
    return 0;
}
