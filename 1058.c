#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct que{
    int score;
    int choice_count;
    int cor_count;
    char cors[6];
    int wrong_count;
    int serial;
}que;

int main(int argc, const char * argv[]) {
    
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    que *ques = (que *) malloc(sizeof(que) * m);
    int i;
    for (i = 0; i < m; i ++) {
        scanf("%d %d %d", &ques[i].score, &ques[i].choice_count, &ques[i].cor_count);
        getchar();
        int j;
        for (j = 0; j < ques[i].cor_count; j ++) {
            scanf("%c", &ques[i].cors[j]);
            getchar();
        }
        ques[i].cors[j] = '\0';
        ques[i].wrong_count = 0;
        ques[i].serial = 1 + i;
    }
    char chr;
    for (i = 0; i < n; i ++) {
        int sum = 0;
        int pos = 0;
        chr = getchar();
        while (chr != '\n') {
            if (chr == '(') {
                int temp;
                scanf("%d", &temp);
                getchar();
                int j;
                char res[6];
                for (j = 0; j < temp; j ++) {
                    scanf("%c", &res[j]);
                    getchar();
                }
                res[j] = '\0';
                if (strcmp(ques[pos].cors, res) == 0) {
                    sum += ques[pos].score;
                } else {
                    ques[pos].wrong_count ++;
                }
                pos ++;
            }
            chr = getchar();
        }
        printf("%d\n", sum);
    }
    
    for (i = 0; i < m; i ++) {
        int j;
        for (j = i + 1; j < m; j ++) {
            if (ques[j].wrong_count > ques[i].wrong_count) {
                que temp = ques[j];
                ques[j] = ques[i];
                ques[i] = temp;
            }
        }
    }
    int res_count = ques[0].wrong_count;
    if (res_count == 0) {
        printf("Too simple");
    } else {
        printf("%d", res_count);
        for (i = 0; i < m; i ++) {
            if (ques[i].wrong_count < res_count) {
                break;
            }
            printf(" %d", ques[i].serial);
        }
    }
    
    return 0;
}
