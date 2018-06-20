//根据情况逐步输出
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char input[100000];
    scanf("%s", input);
    int len = (int)strlen(input);
    
    if (input[0] == '-') {
        printf("-");
    }
    int i, e_pos = 0;
    for (i = 1; i < len; i ++) {
        if (input[i] == 'E') {
            e_pos = i;
            break;
        }
    }
    
    int cycle = 0;
    for (i = e_pos + 2; i < len ; i ++) {
        cycle = (input[i] - '0') + cycle * 10;
    }
    
    if (input[e_pos + 1] == '+') {
        printf("%c", input[1]);
        for (i = 3; i < cycle + 3; i ++) {
            if (i >= e_pos) {
                printf("0");
            } else {
                printf("%c", input[i]);
            }
        }
        if (i < e_pos) {
            printf(".");
            for (; i < e_pos; i ++) {
                printf("%c", input[i]);
            }
        }
    } else {
        printf("0.");
        for (i = 0; i < cycle - 1; i ++) {
            printf("0");
        }
        printf("%c", input[1]);
        for (i = 3; i < e_pos; i ++) {
            printf("%c", input[i]);
        }
    }
    
    return 0;
}

//超时
//#include <stdio.h>
//#include <math.h>
//
//int main(int argc, const char * argv[]) {
//    
//    char input[100000];
//    char chr = getchar();
//    if (chr == '\n') {
//        return 0;
//    }
//    int pos = 0;
//    int symbol_flag = 1;
//    if (chr == '-') {
//        symbol_flag = 0;
//    }
//    
//    input[pos ++] = chr;
//    chr = getchar();
//    int dot_pos = 0;
//    int e_pos = 0;
//    while (chr != '\n') {
//        if (chr == '.') {
//            dot_pos = pos;
//        }
//        if (chr == 'E') {
//            e_pos = pos;
//        }
//        input[pos ++] = chr;
//        chr = getchar();
//    }
//    input[pos] = '\0';
//    char index_symbol_pos = input[e_pos + 1];
//    int index_value = 0;
//    int i;
//    int tens = 0;
//    for (i = pos - 1; i > e_pos + 1; i --) {
//        index_value += (input[i] - '0') * pow(10, tens ++);
//    }
//    input[e_pos] = '\0';
//    
//    for (i = 0; i < index_value; i ++) {
//        if (index_symbol_pos == '+') {
//            char temp = input[dot_pos + 1];
//            input[dot_pos + 1] = input[dot_pos];
//            input[dot_pos ++] = temp;
//            if (dot_pos == e_pos) {
//                input[e_pos ++] = input[dot_pos];
//                input[dot_pos - 1] = '0';
//                input[e_pos] = '\0';
//            }
//        } else {
//            char temp = input[dot_pos - 1];
//            input[dot_pos - 1] = input[dot_pos];
//            input[dot_pos] = temp;
//            if (input[1] == '.') {
//                int j;
//                for (j = e_pos; j >= 1; j --) {
//                    input[j + 1] = input[j];
//                }
//                e_pos ++;
//                input[e_pos] = '\0';
//                input[1] = '0';
//            }
//        }
//    }
//    if (input[e_pos - 1] == '.') {
//        input[e_pos - 1] = '\0';
//    }
//    if (symbol_flag) {
//        for (i = 1; input[i] != '\0'; i ++) {
//            printf("%c", input[i]);
//        }
//    } else {
//        printf("%s", input);
//    }
//    
//    return 0;
//}

