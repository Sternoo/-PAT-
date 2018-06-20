#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    int i = 0;
    int temp = 0;
    int sum = 0;
    for (; i < count; i ++) {
        scanf("%d", &temp);
        sum += temp;
    }
    
    sum *= (count - 1);
    int res = sum * 10 + sum;
    printf("%d", res);
    
    return 0;
}
