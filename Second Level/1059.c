#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int N;
    scanf("%d", &N);
    int *students = (int *)malloc(sizeof(int) * N);
    int i;
    for (i = 0; i < N; i ++) {
        scanf("%d", &students[i]);
    }
    
    int K;
    scanf("%d", &K);
    int list_length = 10;
    int *taken_id = (int *) malloc(sizeof(int) * list_length);
    int taken_count = 0;
    for (i = 0; i < K; i ++) {
        int temp;
        scanf("%d", &temp);
        int j;
        int taken_flag = 1;
        for (j = 0; j < taken_count; j ++) {
            if (temp == taken_id[j]) {
                taken_flag = 0;
                printf("%04d: Checked", temp);
                break;
            }
        }
        if (taken_flag) {
            for (j = 0; j < N; j ++) {
                if (temp == students[j]) {
                    if (j == 0) {
                        printf("%04d: Mystery Award", temp);
                    } else{
                        int k;
                        int t_flag = 1;
                        for (k = 2; k <= sqrt(j + 1) ; k ++) {
                            if ((j + 1) % k == 0) {
                                t_flag = 0;
                                break;
                            }
                        }
                        if (t_flag) {
                            printf("%04d: Minion", temp);
                        } else {
                            printf("%04d: Chocolate", temp);
                        }
                    }
                    if (taken_count >= list_length) {
                        list_length += 10;
                        taken_id = (int *)realloc(taken_id, sizeof(int) * list_length);
                    }
                    taken_id[taken_count ++] = temp;
                    break;
                }
            }
            if (j == N) {
                printf("%04d: Are you kidding?", temp);
            }
        }
        printf("\n");
    }
    free(taken_id);
    free(students);
    return 0;
}
