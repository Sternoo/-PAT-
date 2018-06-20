#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int px_x, px_y, shades_min, shades_max, shades;
    scanf("%d %d %d %d %d", &px_x, &px_y, &shades_min, &shades_max, &shades);
    
    int i = 0;
    for (; i < px_x; i ++) {
        int j = 0;
        for (; j < px_y; j ++) {
            int shade;
            scanf("%d", &shade);
            if (shade >= shades_min && shade <= shades_max) {
                shade = shades;
            }
            printf("%03d", shade);
            
            if (j < px_y - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
