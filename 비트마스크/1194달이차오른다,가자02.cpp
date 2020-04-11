#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

struct State {
    int y;
    int x;
    char key;
    State(int a, int b, char c) : y(a), x(b), key(c) {
    }
};



int bfs(vector<vector<char>>& map, State state) {
    int N = map.size();
    int M = map[0].size();
    queue<State> q;
    q.push(state);

    int cnt = 0;

    while(!q.empty()) {
        int qsize = q.size();
        cnt++;

        for(int i = 0; i < qsize; i++) {
            State curState = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int ty = curState.y + dy[dir];
                int tx = curState.x + dx[dir];
                int tkey = curState.key;
                if(ty < 0 || tx < 0 || ty >= N || tx >= M) continue;
                if(map[ty][tx] == 'G') return cnt;
                if(map[ty][tx] == '#') continue;
                if(map[ty][tx] >= 'A' && map[ty][tx] <= 'F') {
                    if(!(tkey & (1 << (map[ty][tx] - 'A')))) continue;
                    tkey &= ~(1 << (map[ty][tx] - 'A'));
                } else if(map[ty][tx] >= 'a' && map[ty][tx] <= 'f' ) {
                    tkey |= (1 << (map[ty][tx] - 'a'));
                }

                // cout << "=========\n";
                // for(int k = 0; k < N; k++) {
                //     for(int s = 0; s < M; s++) {
                //         caout << map[k][s];
                //     }
                //     cout << '\n';
                // }

                if(tkey >= map[ty][tx]) continue;
                map[ty][tx] = (char)tkey;
                q.push(State(ty, tx, tkey));


            }
        }
    }

    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M));

    int sY, sX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == '0') {
                sY = i;
                sX = j;
            } else if(map[i][j] == '1') {
                map[i][j] = 'G';
            }
        }
    }
    

    cout << bfs(map, State(sY, sX, 0));


    return 0;
}