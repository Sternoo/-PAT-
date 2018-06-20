#include <stdio.h>
#include <stdlib.h>

typedef struct examinee {
    char exam_number[15];
    int test_pc;
    int formal_pc;
}Examinee;

int main(int argc, const char * argv[]) {
    
    int number;
    scanf("%d", &number);
    Examinee *examinees = malloc(sizeof(Examinee) * number);
    int i = 0;
    for (; i < number; i ++) {
        scanf("%s %d %d", examinees[i].exam_number, &examinees[i].test_pc, &examinees[i].formal_pc);
    }
    int count;
    scanf("%d", &count);
    int *seek = malloc(sizeof(int) * count);
    for (i = 0; i < count; i ++) {
        scanf("%d", &seek[i]);
    }
    int j = 0;
    for (; j < count; j ++) {
        int k = 0;
        for (; k < number; k ++) {
            if (examinees[k].test_pc == seek[j]) {
                printf("%s %d\n", examinees[k].exam_number, examinees[k].formal_pc);
                break;
            }
        }
    }
    
    return 0;
}
