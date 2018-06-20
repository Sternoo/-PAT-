//避免超时，直接将配偶映射到数组上
#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    int a[100000] = {-1};
    int i;
    int temp1, temp2;
    for (i = 0; i < n; i ++) {
        scanf("%d %d", &temp1, &temp2);
        a[temp1] = temp2;
        a[temp2] = temp1;
    }
    
    int m;
    scanf("%d", &m);
    int b[100000];
    for (i = 0; i < m; i ++) {
        scanf("%d", &b[i]);
    }
    
    int c[100000];
    int count = 0;
    for (i = 0; i < m; i ++) {
        if (a[b[i]] != -1) {
            int j;
            for (j = 0; j < m; j ++) {
                if (b[j] == a[b[i]]) {
                    break;
                }
            }
            if (j == m) {
                c[count ++] = b[i];
            }
        } else {
            c[count ++] = b[i];
        }
    }
    
    qsort(c, count, sizeof(int), cmp);
    
    printf("%d\n", count);
    for (i = 0; i < count; i ++) {
        printf("%05d", c[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct couple{
//    char man_id[6];
//    char women_id[6];
//    int isCompare;
//}couple;
//
//typedef struct guest{
//    char id[6];
//    int isCompare;
//}guest;
//
//int cmp(const void * a, const void *b) {
//    return strcmp((*(guest *)a).id, (*(guest *)b).id);
//}
//
//int main(int argc, const char * argv[]) {
//    
//    int n;
//    scanf("%d", &n);
//    couple *couples = (couple *)malloc(sizeof(couple) * n);
//    int i;
//    for (i = 0; i < n; i ++) {
//        scanf("%s %s", couples[i].man_id, couples[i].women_id);
//        couples[i].isCompare = 0;
//    }
//    
//    int m;
//    scanf("%d", &m);
//    guest *guests = (guest *)malloc(sizeof(guest) * m);
//    for (i = 0; i < m; i ++) {
//        scanf("%s", guests[i].id);
//        guests[i].isCompare = 0;
//    }
//    qsort(guests, m, sizeof(guest), cmp);
//    
//    int count = 0;
//    for (i = 0; i < m; i ++) {
//        guest *g = &guests[i];
//        int j;
//        for (j = 0; j < n; j ++) {
//            if (couples[j].isCompare) {
//                continue;
//            }
//            char *other;
//            int flag = 0;
//            if (strcmp(g->id, couples[j].man_id) == 0) {
//                other = couples[j].women_id;
//                flag = 1;
//                couples[j].isCompare = 1;
//            } else if (strcmp(g->id, couples[j].women_id) == 0) {
//                other = couples[j].man_id;
//                flag = 1;
//                couples[j].isCompare = 1;
//            }
//            if (flag) {
//                int k;
//                for (k = i + 1; k < m; k ++) {
//                    if (guests[k].isCompare) {
//                        continue;
//                    }
//                    if (strcmp(guests[k].id, other) == 0) {
//                        g->isCompare = 1;
//                        guests[k].isCompare = 1;
//                        count += 2;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    
//    if (!count) {
//        printf("0");
//        return 0;
//    } else {
//        printf("%d\n", m - count);
//    }
//    for (i = 0; i < m; i ++) {
//        if (guests[i].isCompare) {
//            continue;
//        }
//        printf("%s", guests[i].id);
//        if (i < m - count - 1) {
//            printf(" ");
//        }
//    }
//    
//    return 0;
//}
