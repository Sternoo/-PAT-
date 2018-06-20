#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int figure;
    scanf("%d", &figure);
    if (figure/100 != 0) {
        int i;
        for (i = 0; i < figure/100; i ++) {
            printf("B");
        }
        figure = figure % 100;
    }
    if (figure/10 != 0) {
        int i;
        for (i = 0; i < figure/10; i ++) {
            printf("S");
        }
        figure = figure % 10;
    }
    if (figure != 0) {
        int i;
        for (i = 0; i < figure; i ++) {
            printf("%d", i + 1);
        }
    }
    return 0;
}
