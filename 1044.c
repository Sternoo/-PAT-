#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int N;
    scanf("%d", &N);
    getchar();
    
    char lows[12][4] = {{"jan"}, {"feb"}, {"mar"}, {"apr"}, {"may"}, {"jun"}, {"jly"}, {"aug"}, {"sep"}, {"oct"}, {"nov"}, {"dec"}};
    char highs[12][4] = {{"tam"}, {"hel"}, {"maa"}, {"huh"}, {"tou"}, {"kes"}, {"hei"}, {"elo"}, {"syy"}, {"lok"}, {"mer"}, {"jou"}};
    char zero[5] = {"tret"};
    int i;
    for (i = 0; i < N; i ++) {
        char c = getchar();
        int flag = 0;
        char temp[8];
        int count = 0;
        if (c >= '0' && c <= '9') {
            flag = 1;
        }
        while (c != '\n') {
            temp[count ++] = c;
            c = getchar();
        }
        temp[count] = '\0';
        if (flag) {
            int val[3] = {0};
            if (count == 3) {
                val[0] = temp[0] - '0';
                val[1] = temp[1] - '0';
                val[2] = temp[2] - '0';
            } else if (count == 2) {
                val[1] = temp[0] - '0';
                val[2] = temp[1] - '0';
            } else if (count == 1) {
                val[2] = temp[0] - '0';
            }
            int res = val[0] * 100 + val[1] * 10 + val[2];
            if (res == 0) {
                printf("%s", zero);
            } else {
                int tens = res / 13;
                int digits = res % 13;
                if (tens == 0) {
                    printf("%s", lows[digits - 1]);
                } else if (digits == 0) {
                    printf("%s", highs[tens - 1]);
                } else {
                    printf("%s %s", highs[tens - 1], lows[digits - 1]);
                }
            }
        } else {
            int j;
            int t_flag = 0;
            for (j = 0; temp[j] != '\0'; j ++) {
                if (temp[j] == ' ') {
                    t_flag = 1;
                    break;
                }
            }
            if (t_flag) {
                char str1[4];
                char str2[4];
                int k;
                for (k = 0; temp[k] != '\0'; k ++) {
                    if (k < 3) {
                        str1[k] = temp[k];
                    } else if (k > 3) {
                        str2[k - 4] = temp[k];
                    }
                }
                str1[3] = '\0';
                str2[3] = '\0';
                int tens = 0;
                int dights = 0;
                for (k = 0; k < 12; k ++) {
                    if (strcmp(str1, highs[k]) == 0) {
                        tens = k + 1;
                        break;
                    }
                }
                for (k = 0; k < 12; k ++) {
                    if (strcmp(str2, lows[k]) == 0) {
                        dights = k + 1;
                        break;
                    }
                }
                printf("%d", tens * 13 + dights);
                
            } else {
                if (strcmp(temp, zero) == 0) {
                    printf("0");
                } else {
                    int k;
                    for (k = 0; k < 12; k ++) {
                        if (strcmp(temp, lows[k]) == 0) {
                            printf("%d", k + 1);
                            break;
                        }
                    }
                    if (k == 12) {
                        for (k = 0; k < 12; k ++) {
                            if (strcmp(temp, highs[k]) == 0) {
                                printf("%d", (k + 1) * 13);
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (i < N - 1) {
            printf("\n");
        }
    }
    
    return 0;
}
