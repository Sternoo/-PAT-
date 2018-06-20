#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int begin, end;
    scanf("%d %d", &begin, &end);
    int tick = (end - begin) * 1.0 / 100 + 0.5;
    int res[3];
    res[0] = tick / 3600;
    tick %= 3600;
    res[1] = tick / 60;
    tick %= 60;
    res[2] = tick;
    
    printf("%02d:%02d:%02d", res[0], res[1], res[2]);
    
    return 0;
}
