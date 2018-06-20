//需注意，A1与A2有数值输入，但可能为零的情况

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {

    int number;
    scanf("%d", &number);
    int a[5] = {0};
    int count2 = 0;
    int count4 = 0;
    int i;
    int flag1 = 0, flag2 = 0;
    for (i = 0; i < number; i ++) {
        int temp;
        scanf("%d", &temp);
        if (temp % 10 == 0) {
            if (flag1 == 0) {
                flag1 = 1;
            }
            a[0] += temp;
        } else if (temp % 5 == 1) {
            if (flag2 == 0) {
                flag2 = 1;
            }
            a[1] += pow(-1, count2 ++) * temp;
        } else if (temp % 5 == 2) {
            a[2] ++;
        } else if (temp % 5 == 3) {
            a[3] += temp;
            count4 ++;
        } else if (temp % 5 == 4) {
            if (temp > a[4]) {
                a[4] = temp;
            }
        }
    }
    
    int j;
    for (j = 0; j < 5; j++) {
        if (j == 0) {
            if (flag1) {
                printf("%d", a[j]);
            } else {
                printf("N");
            }
        } else if (j == 1) {
            if (flag2) {
                printf("%d", a[j]);
            } else {
                printf("N");
            }
        } else {
            if (a[j] == 0) {
                printf("N");
            } else {
                if(j == 3) {
                    printf("%.1f", a[j] * 1.0 / count4);
                } else {
                    printf("%d", a[j]);
                }
            }
        }
        if (j < 4) {
            printf(" ");
        }
    }
    return 0;
}
