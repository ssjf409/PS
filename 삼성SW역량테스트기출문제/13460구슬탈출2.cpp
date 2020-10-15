#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321

using namespace std;

// 상, 하, 좌, 우
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M;
vector<string> board;

// {{ry, rx}, {by, bx}}
bool visited[11][11][11][11];

int canMove(int y, int x, int other_y, int other_x) {
    if(y == other_y && x == other_x) return 0;
    if(y < 0 || y >= N || x < 0 || x >= M) return 0;
    if(board[y][x] == '.') return 1;
    if(board[y][x] == 'O') return INF;
    return 0;
}

// 상, 하, 좌, 우
//  0,  1,  2,  3
pair<pair<int, int>, pair<int, int>> move(int ry, int rx, int by, int bx, int dir) {
    int rFlag = 1;
    int bFlag = 1;
    while(rFlag == 1 || bFlag == 1) {
        int nry = ry + dy[dir], nrx = rx + dx[dir], nby = by + dy[dir], nbx = bx + dx[dir];
        if(rFlag != INF) {
            rFlag = canMove(nry, nrx, by, bx);
        }

        if(rFlag != INF && rFlag) {
            ry = nry;
            rx = nrx;
        }

        if(rFlag == INF) {
            ry = -1;
            rx = -1;
        }

        
        if(bFlag != INF) {
            bFlag = canMove(nby, nbx, ry, rx);
        }

        if(bFlag != INF && bFlag) {
            by = nby;
            bx = nbx;
        }

        
        if(bFlag == INF) {
            by = -1;
            bx = -1;
        }
        
    }

    if(bFlag == INF) return {{-INF, -INF}, {-INF, -INF}};
    if(rFlag == INF) return {{INF, INF}, {INF, INF}};

    return {{ry, rx}, {by, bx}};
}

int bfs(int ry, int rx, int by, int bx, int oy, int ox) {
    // {{ry, rx}, {by, bx}}
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{ry, rx}, {by, bx}});
    visited[ry][rx][by][bx] = true;

    for(int time = 1; time <= 10; time++) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cry = q.front().first.first;
            int crx = q.front().first.second;
            int cby = q.front().second.first;
            int cbx = q.front().second.second;
            q.pop();

            
            // cout << cry << ' ' << crx << ' ' << cby << ' ' << cbx << endl;

            // cout << "===============\n";
            // for(int i = 0; i < N; i++) {
            //     for(int j = 0; j < M; j++) {
            //         if(i == cry && j == crx) {
            //             cout << 'R';
            //         } else if(i == cby && j == cbx) {
            //             cout << 'B';
            //         } else {
            //             cout << board[i][j];
            //         }
            //     }
            //     cout << endl;
            // }

            for(int dir = 0; dir < 4; dir++) {
                pair<pair<int, int>, pair<int, int>> next = move(cry, crx, cby, cbx, dir);
                int nry = next.first.first;
                int nrx = next.first.second;
                int nby = next.second.first;
                int nbx = next.second.second;

                if(nry == INF) return time;
                if(nry == -INF) continue;
                if(visited[nry][nrx][nby][nbx]) continue;
                visited[nry][nrx][nby][nbx] = true;
                q.push({{nry, nrx}, {nby, nbx}});
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    board.assign(N, "");

    for(int i = 0; i < N; i++){
        cin >> board[i];
    }



    memset(visited, false, sizeof(visited));

    int by, bx, ry, rx, oy, ox;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'B') {
                board[i][j] = '.';
                by = i;
                bx = j;
            } else if(board[i][j] == 'R') {
                board[i][j] = '.';
                ry = i;
                rx = j;
            } else if(board[i][j] == 'O') {
                oy = i;
                ox = j;
            }
        }
    }

    cout << bfs(ry, rx, by, bx, oy, ox);


    return 0;
}