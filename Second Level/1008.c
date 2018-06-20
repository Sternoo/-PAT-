#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

int main(int argc, const char * argv[]) {
    int numer_count, move_number;
    scanf("%d %d", &numer_count, &move_number);
    
    LNode *linkList = malloc(sizeof(LNode));
    
    int i = 0;
    for (; i < numer_count; i ++) {
        int data;
        scanf("%d", &data);
        LNode * next = malloc(sizeof(LNode));
        next->data = data;
        linkList->next = next;
        linkList = next;
        printf("%d ", linkList->data);
    }
    
    move_number = move_number % numer_count;
    if (move_number) {
        linkList[numer_count].next = linkList;
        linkList->next = &linkList[numer_count - move_number];
    }
    int j = 1;
    for (; j <= numer_count; j ++) {
        printf("%d", linkList[j].data);
        if (j < numer_count) {
            printf(" ");
        }
    }
    
    return 0;
}
