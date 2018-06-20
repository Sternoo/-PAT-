#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char chrs[6] = {'P', 'A', 'T', 'e', 's', 't'};
    int counts[6] = {0};
    
    char c = getchar();
    int sum = 0;
    while (c != '\n') {
        int i = 0;
        for (; i < 6; i ++) {
            if (c == chrs[i]) {
                counts[i] ++;
                sum ++;
                break;
            }
        }
        c = getchar();
    }
    int i = 0;
    for (; sum > 0; i ++) {
        if (counts[i] > 0) {
            printf("%c", chrs[i]);
            counts[i] --;
            sum --;
        }
        if (i == 5) {
            i = -1;
        }
    }
    
    return 0;
}
