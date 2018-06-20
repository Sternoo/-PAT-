#include <stdio.h>
#include "string.h"

#define chartonumber(x) (x-'0')

int main(int argc, const char * argv[]) {
    
    char str[101];
    scanf("%s", str);
    int i;
    int sum = 0;
    for (i = 0; i < strlen(str); i++) {
        sum += (int)chartonumber(str[i]);
    }
    
    char *res[4] = {};
    int j = 0;
    int numer = 0;
    do {
        int temp = sum - sum/10*10;
        char *s = NULL;
        switch (temp) {
            case 0:
                s = "ling";
                break;
            case 1:
                s = "yi";
                break;
            case 2:
                s = "er";
                break;
            case 3:
                s = "san";
                break;
            case 4:
                s = "si";
                break;
            case 5:
                s = "wu";
                break;
            case 6:
                s = "liu";
                break;
            case 7:
                s = "qi";
                break;
            case 8:
                s = "ba";
                break;
            case 9:
                s = "jiu";
                break;
        }
        res[j++] = s;
        numer ++;
        sum = sum/10;
    } while (sum);
    
    do {
        printf("%s", res[--numer]);
        if (numer) {
            printf(" ");
        }
    } while (numer);
    
    return 0;
}
