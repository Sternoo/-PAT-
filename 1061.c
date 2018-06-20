#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int std_num, ques_num;
    scanf("%d %d", &std_num, &ques_num);
    int *ques_marks = malloc(sizeof(int) * ques_num);
    int *ques_ans = malloc(sizeof(int) * ques_num);
    int i = 0;
    for (; i < ques_num; i ++) {
        int mark;
        scanf("%d", &mark);
        ques_marks[i] = mark;
    }
    for (i = 0; i < ques_num; i ++) {
        int ans;
        scanf("%d", &ans);
        ques_ans[i] = ans;
    }
    for (i = 0; i < std_num; i ++) {
        int mark_res = 0;
        int j = 0;
        for (; j < ques_num; j ++) {
            int std_ans;
            scanf("%d", &std_ans);
            if (std_ans == ques_ans[j]) {
                mark_res += ques_marks[j];
            }
        }
        printf("%d\n", mark_res);
    }
    free(ques_marks);
    free(ques_ans);
    return 0;
}
