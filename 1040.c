#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char str[100001];
    scanf("%s", str);
    int i, count_t = 0;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] == 'T')
            count_t++;
    }
    int count_p = 0;
    int count_pat = 0;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] == 'P')
            count_p ++;
        else if (str[i] == 'T')
            count_t --;
        else if (str[i] == 'A')
            count_pat = (count_pat + (count_p * count_t) % 1000000007) % 1000000007;
    }
    printf("%d", count_pat);
    return 0;
}
