#include <stdio.h>
#include <stdlib.h>

struct student {
    char *name;
    char *number;
    int score;
};

void rank(struct student s[100], int number){
    int i;
    int max = 0, min = 0;
    for (i = 0; i < number; i ++) {
        if (s[i].score > s[max].score) {
            max = i;
        } else if (s[i].score < s[min].score) {
            min = i;
        }
    }
    printf("%s %s\n%s %s", s[max].name, s[max].number, s[min].name, s[min].number);
}

int main(int argc, const char * argv[]) {

    int number;
    scanf("%d", &number);
    struct student student[100] = {};
    int i = 0;
    for (i = 0; i < number; i ++) {
        struct student stu;
        stu.name = (char *)malloc(10*sizeof(char));
        stu.number = (char *)malloc(10*sizeof(char));
        stu.score = 0;
        scanf("%s %s %d", stu.name, stu.number, &stu.score);
        student[i] = stu;
    }
    rank(student, number);
    return 0;
}
