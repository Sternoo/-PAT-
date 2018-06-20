#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    char *a[4];
    int i;
    for (i=0; i < 4; i ++) {
        char *str = malloc(sizeof(char) * 60);
        scanf("%s", str);
        a[i] = str;
    }
    int j;
    char *first = a[0];
    char *second = a[1];
    int flag = 0;
    for (j = 0; &first[j] != '\0'; j ++) {
        if (flag == 0) {
            if (first[j] >= 'A' && first[j] <= 'G') {
                if (second[j] == first[j]) {
                    flag = 1;
                    switch (first[j]) {
                        case 'A':
                            printf("MON ");
                            break;
                        case 'B':
                            printf("TUE ");
                            break;
                        case 'C':
                            printf("WED ");
                            break;
                        case 'D':
                            printf("THU ");
                            break;
                        case 'E':
                            printf("FRI ");
                            break;
                        case 'F':
                            printf("SAT ");
                            break;
                        case 'G':
                            printf("SUN ");
                            break;
                        default:
                            break;
                    }
                }
            }
        } else if(flag == 1) {
            if (first[j] >= 'A' && first[j] <= 'N') {
                if (second[j] == first[j]) {
                    printf("%d", first[j] - 'A' + 10);
                    break;
                }
            }
            else if (first[j] >= '0' && first[j] <= '9') {
                if (second[j] == first[j]) {
                    printf("0%c", first[j]);
                    break;
                }
            }
        }
    }
    printf(":");
    char *third = a[2];
    char *four = a[3];
    int k;
    for (k = 0; &third[k] != '\0'; k++) {
        if ((third[k] >= 'A' && third[k] <= 'Z') || (third[k] >= 'a' && third[k] <= 'z')) {
            if (third[k] == four[k]) {
                if (k < 10) {
                    printf("0%d", k);
                } else {
                    printf("%d", k);
                }
                break;
            }
        }
    }
    return 0;
}
