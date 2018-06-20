#include <stdio.h>

typedef struct character{
    char chr;
    int count;
}character;

int main(int argc, const char * argv[]) {
    
    char chr = getchar();
    int chr_count = 0;
    character characters[26];
    while (chr != '\n') {
        if (chr >= 'A' && chr <= 'Z') {
            chr += 32;
        }
        if (chr >= 'a' && chr <= 'z') {
            int i = 0;
            for (; i < chr_count; i ++) {
                if (characters[i].chr == chr) {
                    characters[i].count ++;
                    break;
                }
            }
            if (i == chr_count) {
                characters[chr_count].chr = chr;
                characters[chr_count++].count = 1;
            }
        }
        chr = getchar();
    }
    int i = 0;
    for (; i < chr_count - 1; i ++) {
        int j = i + 1;
        for (; j < chr_count; j ++) {
            if (characters[j].count > characters[i].count) {
                character temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;
            }
        }
    }
    int k;
    char chr_min = characters[0].chr;
    int count_max = characters[0].count;
    for (k = 1; k < chr_count; k ++) {
        if (characters[k].count < count_max) {
            break;
        }
        if (characters[k].chr < chr_min) {
            chr_min = characters[k].chr;
            count_max = characters[k].count;
        }
    }
    printf("%c %d", chr_min, count_max);
    
    return 0;
}
