#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char broken[129];
    char c_broken = getchar();
    int count = 0;
    int flag = 0;
    while (c_broken != '\n') {
        int j = 0;
        for (; j < count; j ++) {
            if (broken[j] == c_broken) {
                break;
            }
        }
        if (j == count) {
            broken[count ++] = c_broken;
        }
        if (c_broken == '+') {
            flag = 1;
            c_broken = getchar();
            continue;
        }
        if (c_broken >= 'A' && c_broken <= 'Z') {
            broken[count ++] = c_broken + 32;
        }
        if (c_broken >= 'a' && c_broken <='z') {
            broken[count ++] = c_broken - 32;
        }
        c_broken = getchar();
    }
    
    char c;
    do {
        c = getchar();
        if (c >= 'A' && c <= 'Z') {
            if (flag) {
                continue;
            }
        }
        int j = 0;
        for (; j < count; j ++) {
            if (broken[j] == c) {
                break;
            }
        }
        if (j == count) {
            printf("%c", c);
        }
        
    } while (c != '\n');
    
    return 0;
}
