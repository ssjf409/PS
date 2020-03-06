#include <iostream>
#include <vector>
#define INF 987654321
#define MAX_TRIAL 10

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

struct bState {
    int ry = 0;
    int rx = 0;
    int by = 0;
    int bx = 0;
};


int getMinTrial(vector<vector<char>>& map, bState state, int trial) {
    if(trial == 0) return INF;
    int ret = INF;

    for(int direction = 0; direction < 4; direction++) {
        bState nowState;
        // nowState = getState(map, state, direction);
        if(1) {

        }
        ret = min(ret, getMinTrial(map, state, trial - 1));
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M));
    bState startbState;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            switch(map[i][j]) {
                case 'R':
                startbState.ry = i, startbState.rx = j;
                break;
                case 'B':
                startbState.by = i, startbState.bx = j;
                break;
            }
        }
    }

    getMinTrial(map, startbState, MAX_TRIAL);
    return 0;
}