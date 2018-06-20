#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char chr = getchar();
    int sum = 0;
    while (chr != '\n') {
        if (chr >= 'A' && chr <= 'Z') {
            sum += chr - 'A' + 1;
        } else if (chr >= 'a' && chr <= 'z') {
            sum += chr - 'a' + 1;
        }
        chr = getchar();
    }
    
    int count_zero = 0;
    int count_one = 0;
    while (sum) {
        if (sum % 2) {
            count_one ++;
        } else {
            count_zero ++;
        }
        sum /= 2;
    }
    printf("%d %d", count_zero, count_one);
    
    return 0;
}
