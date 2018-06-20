#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud{
    char name[9];
    int height;
}stud;

int cmp(const void * a, const void * b) {
    stud *a1 = (stud *)a;
    stud *b1 = (stud *)b;
    if (a1->height != b1->height) {
        return b1->height - a1->height;
    } else {
        return strcmp(a1->name, b1->name);
    }
}

int main(int argc, const char * argv[]) {
    
    int n, k;
    scanf("%d %d", &n, &k);
    stud *studs = (stud *) malloc(sizeof(stud) * n);
    int i;
    for (i = 0; i < n; i ++) {
        scanf("%s %d", studs[i].name, &studs[i].height);
    }
    qsort(studs, n, sizeof(stud), cmp);
    
    int others = n / k;
    int others_mid = others / 2;
    int last = others + n % k;
    int last_mid = last / 2;
    stud *last_stud = (stud *) malloc(sizeof(stud) * last);
    
    int flag = 1;
    int pos_count = 0;
    for (i = 0; i < last; i ++) {
        if (flag) {
            last_stud[last_mid + pos_count] = studs[i];
            pos_count ++;
            flag = 0;
        } else {
            last_stud[last_mid - pos_count] = studs[i];
            flag = 1;
        }
    }
    for (i = 0; i < last; i ++) {
        printf("%s", last_stud[i].name);
        if (i < last - 1) {
            printf(" ");
        }
    }
    free(last_stud);
    if (n > last) {
        stud *others_stud = (stud *) malloc(sizeof(stud) * (n - last));
        printf("\n");
        int line = 0;
        pos_count = 0;
        int postion = 0;
        flag = 1;
        for (i = last; i < n; i ++) {
            if (flag) {
                others_stud[line * others + others_mid + pos_count] = studs[i];
                pos_count ++;
                flag = 0;
            } else {
                others_stud[line * others + others_mid - pos_count] = studs[i];
                flag = 1;
            }
            if (postion % others == others - 1) {
                pos_count = 0;
                flag = 1;
                line ++;
            }
            postion ++;
        }
        int p_count = 1;
        for (i = 0; i < n - last; i ++) {
            printf("%s", others_stud[i].name);
            if (p_count % others == 0) {
                p_count = 1;
                printf("\n");
            } else {
                printf(" ");
                p_count ++;
            }
        }
        free(others_stud);
    }
    free(studs);
    
    return 0;
}
