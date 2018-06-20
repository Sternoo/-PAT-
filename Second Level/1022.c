#include <stdio.h>
#include <stdlib.h>

#define LISTLENGTH 10
#define INCREMENT 10

int main(int argc, const char * argv[]) {
    
    int A, B, D;
    scanf("%d %d %d", &A, &B, &D);
    int temp = A + B;
    if (temp == 0) {
        printf("0");
        return 0;
    }
    int left = 0;
    int list_length = LISTLENGTH;
    int *res_list = malloc(sizeof(int) * list_length);
    int count = 0;
    while (temp) {
        if (count + 1 >= list_length) {
            list_length += INCREMENT;
            res_list = realloc(res_list, sizeof(int) * list_length);
        }
        left = temp % D;
        res_list[count++] = left;
        temp /= D;
    }
    int j;
    for (j = count - 1; j >= 0; j --) {
        printf("%d", res_list[j]);
    }
    
    return 0;
}
