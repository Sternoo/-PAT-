#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n, cnt = 0;
    double temp, sum = 0.0;
    char a[100], b[100];
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf", temp);
        int j;
        int flag = 0;
        for (j = 0; a[j] != '\0'; j ++) {
            if (a[j] != b[j])
                flag = 1;
        }
        if (flag || temp > 1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", a);
        } else {
            sum += temp;
            cnt ++;
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (cnt == 1){
        printf("The average of 1 number is %.2lf\n", sum);
    } else {
        printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
    }
    
    return 0;
}
