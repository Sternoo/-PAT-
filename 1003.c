#include <stdio.h>

void charge_pat() {
    char str[101];
    scanf("%s", str);
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] != 'P' && str[i]!= 'A' && str[i] != 'T') {
            printf("NO\n");
            return;
        }
    }
    int flag = 0;
    int pos = 0;
    int count1 = 0, count2 = 0, count3 = 0;
    for (i = 0; str[i] != '\0'; i ++) {
        if (pos == 0) {
            if (str[i] == 'P') {
                pos = 1;
            } else if (str[i] == 'A') {
                count1 ++;
            } else {
                flag = 1;
                break;
            }
        } else if(pos == 1) {
            if (str[i] == 'P') {
                flag = 1;
                break;
            } else if (str[i] == 'A') {
                count2 ++;
            } else {
                if (!count2) {
                    flag = 1;
                    break;
                } else {
                    pos = 2;
                }
            }
        } else {
            if (str[i] == 'P') {
                flag = 1;
                break;
            } else if (str[i] == 'A') {
                count3 ++;
            } else {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) {
        if (count3 == count1 * count2 && pos == 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }
}


int main(int argc, const char * argv[]) {
    int number;
    scanf("%d", &number);
    while (number) {
        charge_pat();
        number --;
    }
    return 0;
}
