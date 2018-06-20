#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int adress[100000] = {0}, data[100000] = {0};
    int next, n, k;
    scanf("%d %d %d", &next, &n, &k);
    int i;
    for (i = 0; i < n; i ++) {
        int t_adress, t_data, t_next;
        scanf("%d %d %d", &t_adress, &t_data, &t_next);
        adress[t_adress] = t_next;
        data[t_adress] = t_data;
    }
    
    int res[100000] = {0};
    int count = 0;
    while (next != - 1) {
        res[count ++] = next;
        next = adress[next];
    }
    
    int re_count = count / k;
    int j;
    for (i = 0; i < re_count; i ++) {
        int max = (i + 1) * k;
        for (j = i * k; j < --max; j ++) {
            int temp = res[j];
            res[j] = res[max];
            res[max] = temp;
        }
    }
    for (i = 0; i < count; i ++) {
        if (i == count - 1) {
            printf("%05d %d -1\n", res[i], data[res[i]]);
        } else {
            printf("%05d %d %05d\n", res[i], data[res[i]], res[i + 1]);
        }
    }
    
    return 0;
}

//下面代码超时
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//    int adress;
//    int data;
//    int next;
//}node;
//
//int main(int argc, const char * argv[]) {
//    
//    int next, n, k;
//    scanf("%d %d %d", &next, &n, &k);
//    node *nodes = (node *)malloc(sizeof(node) * n);
//    
//    int i;
//    for (i = 0; i < n; i ++) {
//        scanf("%d %d %d", &nodes[i].adress, &nodes[i].data, &nodes[i].next);
//    }
//    
//    node *seq = (node *)malloc(sizeof(node) * n);
//    int count = 0;
//    while (next != -1) {
//        for (i = 0; i < n; i ++) {
//            if (nodes[i].adress == next) {
//                next = nodes[i].next;
//                seq[count ++] = nodes[i];
//                break;
//            }
//        }
//    }
//    
//    node *res = (node *)malloc(sizeof(node) * count);
//    int res_pos = 0;
//    int j;
//    for (j = 0; j < count / k; j ++) {
//        for (i = (j + 1) * k - 1; i >= j * k; i --) {
//            res[res_pos ++] = seq[i];
//        }
//    }
//    for (i = count/k * k; i < count; i ++) {
//        res[res_pos ++] = seq[i];
//    }
//    
//    for (i = 0; i < count; i ++) {
//        if (i == count - 1) {
//            printf("%05d %d -1", res[i].adress, res[i].data);
//        } else {
//            res[i].next = res[i + 1].adress;
//            printf("%05d %d %05d\n", res[i].adress, res[i].data, res[i].next);
//        }
//    }
//    
//    return 0;
//}
