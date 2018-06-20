#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud{
    char number[9];
    int d_score;
    int c_score;
}stud;

int cmp(const void * a, const void *b) {
    stud *stu1 = (stud *)a;
    stud *stu2 = (stud *)b;
    if (stu1->d_score + stu1->c_score == stu2->d_score + stu2->c_score) {
        if (stu1->d_score == stu2->d_score) {
            return strcmp(stu1->number, stu2->number);
        } else {
            return stu2->d_score - stu1->d_score;
        }
    } else {
        return (stu2->d_score + stu2->c_score) - (stu1->d_score + stu1->c_score);
    }
}

int main(int argc, const char * argv[]) {
    
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    stud *studs = (stud *)malloc(sizeof(stud) * n);
    int i;
    for (i = 0; i < n; i ++) {
        scanf("%s %d %d", studs[i].number, &studs[i].d_score, &studs[i].c_score);
    }
    
    stud *first = (stud *)malloc(sizeof(stud) * n);
    int first_count = 0;
    stud *second = (stud *)malloc(sizeof(stud) * n);
    int second_count = 0;
    stud *thrid = (stud *)malloc(sizeof(stud) * n);
    int thrid_count = 0;
    stud *last = (stud *)malloc(sizeof(stud) * n);
    int last_count = 0;
    
    for (i = 0; i < n; i ++) {
        int t_d = studs[i].d_score;
        int t_c = studs[i].c_score;
        if (t_d >= l && t_c >= l) {
            if (t_d >= h && t_c >= h) {
                first[first_count ++] = studs[i];
            } else if(t_d >= h && t_c < h) {
                second[second_count ++] = studs[i];
            } else if(t_d < h && t_c < h && t_d >= t_c) {
                thrid[thrid_count ++] = studs[i];
            } else {
                last[last_count ++] = studs[i];
            }
        }
    }
    
    qsort(first, first_count, sizeof(stud), cmp);
    qsort(second, second_count, sizeof(stud), cmp);
    qsort(thrid, thrid_count, sizeof(stud), cmp);
    qsort(last, last_count, sizeof(stud), cmp);
    
    printf("%d", first_count + second_count + thrid_count + last_count);
    for (i = 0; i < first_count; i ++) {
        printf("\n");
        printf("%s %d %d", first[i].number, first[i].d_score, first[i].c_score);
    }
    
    for (i = 0; i < second_count; i ++) {
        printf("\n");
        printf("%s %d %d", second[i].number, second[i].d_score, second[i].c_score);
    }
    
    for (i = 0; i < thrid_count; i ++) {
        printf("\n");
        printf("%s %d %d", thrid[i].number, thrid[i].d_score, thrid[i].c_score);
    }
    
    for (i = 0; i < last_count; i ++) {
        printf("\n");
        printf("%s %d %d", last[i].number, last[i].d_score, last[i].c_score);
    }
    
    return 0;
}
