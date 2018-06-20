#include <stdio.h>
#include <stdlib.h>

typedef struct wants_bead{
    char type;
    int count;
}wants_bead;

int main(int argc, const char * argv[]) {
    
    char given[1001], want[1001];
    scanf("%s", given);
    getchar();
    scanf("%s", want);
    
    int list_length = 10;
    wants_bead *wants_beads = (wants_bead *)malloc(sizeof(wants_bead) * list_length);
    int count = 0;
    int i = 0;
    int sum = 0;
    int wants_total = 0;
    for (; want[i] != '\0'; i ++) {
        wants_total ++;
        sum ++;
        int j = 0;
        for (; j < count; j ++) {
            if (wants_beads[j].type == want[i]) {
                wants_beads[j].count ++;
                break;
            }
        }
        if (j == count) {
            if (count >= list_length) {
                list_length += 10;
                wants_beads = realloc(wants_beads, sizeof(wants_bead) * list_length);
            }
            wants_beads[count].type = want[i];
            wants_beads[count ++].count = 1;
        }
    }
    int k = 0;
    int given_total = 0;
    for (; given[k] != '\0'; k ++) {
        given_total ++;
        if (sum > 0) {
            int l = 0;
            for (; l < count; l ++) {
                if (given[k] == wants_beads[l].type) {
                    if (wants_beads[l].count > 0) {
                        wants_beads[l].count --;
                        sum --;
                    }
                }
            }
        }
    }
    if (sum == 0) {
        printf("Yes %d", given_total - wants_total);
    } else {
        printf("No %d", sum);
    }
    
    return 0;
}
