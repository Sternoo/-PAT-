//直接用数列存储每一个分数会超时
#include <stdio.h>
#include <stdlib.h>

#define LISTLENGTH 10
#define INCREMENT 10

typedef struct score_type {
    int score;
    int count;
}score_type;

int main(int argc, const char * argv[]) {
    
    int count;
    scanf("%d", &count);
    int list_length = LISTLENGTH;
    score_type *types = malloc(sizeof(score_type) * list_length);
    
    int st_count = 0;
    int i = 0;
    for (; i < count; i ++) {
        int j = 0;
        int temp_score;
        scanf("%d", &temp_score);
        for (; j < st_count; j ++) {
            if (types[j].score == temp_score) {
                types[j].count ++;
                break;
            }
        }
        if (j == st_count) {
            if (st_count >= list_length) {
                list_length += INCREMENT;
                types = realloc(types, sizeof(score_type) * list_length);
            }
            types[st_count].score = temp_score;
            types[st_count].count = 1;
            st_count ++;
        }
        
    }
    
    int number;
    scanf("%d", &number);
    int j = 0;
    for (; j < number; j ++) {
        int t_score;
        scanf("%d", &t_score);
        int k = 0;
        for (; k < st_count; k ++) {
            if (types[k].score == t_score) {
                printf("%d", types[k].count);
                break;
            }
        }
        if (k == st_count) {
            printf("0");
        }
        if (j < number - 1) {
            printf(" ");
        }
    }
    
    return 0;
}
