#include <iostream>
#include <vector>
#define SNAKE 1
#define APPLE 9

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N;
vector<vector<int>> board;

struct State {
    int hy;
    int hx;
    int ty;
    int tx;
    int dir;

    State(int a, int b, int c, int d, int e) : hy(a), hx(b), ty(c), tx(d), dir(e) {

    }
};

int main() {
    cin >> N;
    board.assign(N, vector<int>(N, -1));

    int K, y, x, L;
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> y >> x;
        board[y - 1][x - 1] = APPLE;
    }
    cin >> L;
    vector<pair<int, char>> cmd(L);

    for(int i = 0; i < L; i++) {
        cin >> cmd[i].first >> cmd[i].second;
    }


    State cur(0, 0, 0, 0, 0);
    board[0][0] = 0;
    
    int step = 1;
    int cmdIdx = 0;

    while(true) {
        int ny = cur.hy + dy[cur.dir];
        int nx = cur.hx + dx[cur.dir];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) break;
        if(board[ny][nx] >= 0 && board[ny][nx] < 4) break;

        // 헤드
        cur.hy = ny;
        cur.hx = nx;
        


        // 테일
        if(board[ny][nx] != APPLE) {
            int tny = cur.ty + dy[board[cur.ty][cur.tx]];
            int tnx = cur.tx + dx[board[cur.ty][cur.tx]];
            board[cur.ty][cur.tx] = -1;
            cur.ty = tny;
            cur.tx = tnx;
        }


        if(cmdIdx != cmd.size()) {
            if(cmd[cmdIdx].first == step) {
                if(cmd[cmdIdx].second == 'D') {
                    cur.dir = (cur.dir + 1) % 4;
                } else {
                    cur.dir = (cur.dir - 1 + 4) % 4;
                }
                cmdIdx++;
            }
        }
        
        board[ny][nx] = cur.dir;
        

        step++;
    }


    cout << step;

    return 0;
}