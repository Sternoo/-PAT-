#include <stdio.h>

int main(int argc, const char *argv[]) {
    
    char word[81];
    char c;
    int i = 0;
    while ((c = getchar())) {
        if (c == '\n') {
            break;
        }
        word[i++] = c;
    }
    word[i] = '\0';
    int count = 0;
    int space[41] = {0};
    int j = 0;
    for (; word[j] != '\0'; j ++) {
        if (word[j] == ' ') {
            space[count ++] = j;
        }
    }
    int k;
    int start;
    int end = i;
    for (k = count; k >= 0; k --) {
        start = space[k - 1];
        if (k > 0) {
            start += 1;
        }
        for (; start < end; start ++) {
            printf("%c", word[start]);
        }
        if (k > 0) {
            printf(" ");
        }
        end = space[k - 1];
    }
    
    return 0;
}
