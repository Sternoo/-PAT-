#include <stdio.h>
#include <stdlib.h>

typedef struct team{
    int number;
    int score;
}team;

int main(int argc, const char * argv[]) {
    
    int N;
    scanf("%d",&N);
    int list_length = 10;
    int team_count = 0;
    team *team_list = (team *)malloc(sizeof(team) * list_length);
    
    int i = 0;
    for (; i < N; i ++) {
        int temp_number = 0;
        int stu_number = 0;
        int temp_score = 0;
        scanf("%d-%d %d", &temp_number, &stu_number, &temp_score);
        int j;
        for (j = 0; j < team_count; j ++) {
            if (temp_number == team_list[j].number) {
                team_list[j].score += temp_score;
            }
        }
        if (j == team_count) {
            if (team_count >= list_length) {
                list_length += 10;
                team_list = (team *)realloc(team_list, sizeof(team) * list_length);
            }
            team_list[team_count].number = temp_number;
            team_list[team_count ++].score = temp_score;
        }
    }
    int id = 0;
    int max = 0;
    for (i = 0; i < team_count; i ++) {
        if (team_list[i].score > max) {
            id = i;
            max = team_list[i].score;
        }
    }
    printf("%d %d", team_list[id].number, team_list[id].score);
    free(team_list);
    
    return 0;
}
