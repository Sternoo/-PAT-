//测试点1，2不通过原因：输出时，不仅要考虑上界，还需要考虑下界，若选择的编号需大于等于1.
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char hands[10][5], eyes[10][5], mouthes[10][5];
    char c = getchar();
    int line = 0;
    int h_count = 0;
    int e_count = 0;
    int m_count = 0;
    while (1) {
        if (c == '\n') {
            line ++;
            if (line > 2) {
                break;
            }
        } else {
            if (c == '[') {
                c = getchar();
                int j;
                for (j = 0; c != ']'; j ++) {
                    if (line == 0) {
                        hands[h_count][j] = c;
                    } else if(line == 1) {
                        eyes[e_count][j] = c;
                    } else {
                        mouthes[m_count][j] = c;
                    }
                    c = getchar();
                }
                if (line == 0) {
                    hands[h_count++][j] = '\0';
                } else if(line == 1) {
                    eyes[e_count++][j] = '\0';
                } else {
                    mouthes[m_count++][j] = '\0';
                }
            }
        }
        c = getchar();
    }
    
    int K;
    scanf("%d", &K);
    int i;
    int l_hand, l_eye, mouth, r_eye, r_hand;
    for (i = 0; i < K; i ++) {
        scanf("%d %d %d %d %d", &l_hand, &l_eye, &mouth, &r_eye, &r_hand);
        if (l_hand > h_count || l_eye > e_count || mouth > m_count || r_eye > e_count || r_hand > h_count || l_hand > h_count || l_eye < 1 || mouth < 1 || r_eye < 1 || r_hand < 1) {
            printf("Are you kidding me? @\\/@");
        } else{
            printf("%s(%s%s%s)%s", hands[l_hand - 1], eyes[l_eye - 1], mouthes[mouth - 1], eyes[r_eye - 1], hands[r_hand - 1]);
        }
        if (i < K - 1) {
            printf("\n");
        }
    }
    
    return 0;
}
