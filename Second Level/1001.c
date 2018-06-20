#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a;
    scanf("%d", &a);
    int step = 0;
    while (a != 1) {
        ++step;
        if (a%2 == 0) {
            a = a >> 1;
        } else {
            a = ((3 * a) + 1) >> 1;
        }
    }
    printf("%d", step);
    
    return 0;
}
