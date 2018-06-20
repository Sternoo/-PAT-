//注意上下界判断
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int cal = 20140906;
    
    int count;
    scanf("%d", &count);
    int count_p = 0;
    int i = 0;
    char *max_name = NULL;
    char *min_name = NULL;
    int max_cal = 0;
    int min_cal = 0;
    int flag = 1;
    for (; i < count; i ++) {
        char *t_name = malloc(sizeof(char) * 6);
        int t_year, t_month, t_day;
        scanf("%s %d/%d/%d", t_name, &t_year, &t_month, &t_day);
        int temp_cal = t_year * 10000 + t_month * 100 + t_day;
        if (temp_cal > cal || temp_cal + 2000000 < cal) {
            continue;
        } else {
            if (flag) {
                max_cal = min_cal = temp_cal;
                max_name = min_name = t_name;
                flag = 0;
            } else {
                if (temp_cal > max_cal) {
                    max_cal = temp_cal;
                    max_name = t_name;
                } else if (temp_cal < min_cal) {
                    min_cal = temp_cal;
                    min_name = t_name;
                }
            }
        }
        count_p ++;
    }
    if (count_p) {
        printf("%d %s %s", count_p, min_name, max_name);
    } else {
        printf("0");
    }
    
    return 0;
}
