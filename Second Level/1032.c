#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a[100001] = {0};
    int number;
    scanf("%d", &number);
    int i, max = 0, pos = 0;
    for (i = 0; i < number; i ++) {
        int school, score;
        scanf("%d %d", &school, &score);
        a[school] += score;
        if (a[school] > max) {
            max = a[school];
            pos = school;
        }
    }
    printf("%d %d", pos, a[pos]);
    
    return 0;
}
