#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int M;
    scanf("%d", &M);
    int mask = 0;
    int num = 0;
    char cmd[10];
    for(int i = 0; i < M; i++) {
        scanf("%s", cmd);
        if(strcmp(cmd, "add") == 0) {
            scanf("%d", &num);
            num--;
            mask |= (1 << num);
        } else if(strcmp(cmd, "check") == 0) {
            scanf("%d", &num);
            num--;
            if(mask & (1 << num)) {
                printf("1\n");
            } else {
                printf("0\n");
            }               
        } else if(strcmp(cmd, "remove") == 0) {
            scanf("%d", &num);
            num--;
            if(mask & (1 << num)) {
                mask &= ~(1 << num);
            }
        } else if(strcmp(cmd, "toggle") == 0) {
            scanf("%d", &num);
            num--;
            mask ^= (1 << num);
        } else if(strcmp(cmd, "all") == 0) {
            mask |= ((1 << M) - 1);
        } else if(strcmp(cmd, "empty") == 0) {
            mask &= 0;
        }
    }
    return 0;
}