#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char require[81];
    char input[81];
    scanf("%s %s", require, input);
    
    int i;
    char re_have[81];
    int re_count = 0;
    for (i = 0; require[i] != '\0'; i ++) {
        if (require[i] >= 'a' && require[i] <= 'z') {
            require[i] -= 32;
        }
        int j = 0;
        for (; j < re_count; j ++) {
            if (re_have[j] == require[i]) {
                break;
            }
        }
        if (j == re_count) {
            re_have[re_count++] = require[i];
        }
    }
    
    char in_have[81];
    int in_count = 0;
    for (i = 0; input[i] != '\0'; i ++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] -= 32;
        }
        int j = 0;
        for (; j < in_count; j ++) {
            if (in_have[j] == input[i]) {
                break;
            }
        }
        if (j == in_count) {
            in_have[in_count++] = input[i];
        }
    }
    
    for (i = 0; i < re_count; i ++) {
        int j = 0;
        for (; j < in_count; j ++) {
            if (re_have[i] == in_have[j]) {
                break;
            }
        }
        if (j == in_count) {
            printf("%c", re_have[i]);
        }
    }
    
    return 0;
}
