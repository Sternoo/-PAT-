#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char password[21];
    int test_count;
    scanf("%s %d", password, &test_count);
    getchar();
    int i = 0;
    int count = 0;
    for (; i < test_count; i ++) {
        char temp[100];
        fgets(temp, 100, stdin);
        unsigned long length = strlen(temp);
        if (temp[length - 1] == '\n') {
            temp[length - 1] = '\0';
        }
        if (strcmp(temp, "#") == 0) {
            return 0;
        } else if (strcmp(temp, password) == 0) {
            printf("Welcome in\n");
            return 0;
        } else {
            printf("Wrong password: %s\n", temp);
            count ++;
        }
        
    }
    if (count >= test_count) {
        printf("Account locked");
        return 0;
    }
    return 0;
}
