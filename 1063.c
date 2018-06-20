#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    double a, b;
    scanf("%lf %lf", &a, &b);
    getchar();
    double max = sqrt(pow(a, 2) + pow(b, 2));
    int i;
    for (i = 1; i < count; i ++) {
        scanf("%lf %lf", &a, &b);
        getchar();
        double temp = sqrt(pow(a, 2) + pow(b, 2));
        if (temp > max) {
            max = temp;
        }
    }
    printf("%.2lf", max);
    
    return 0;
}
