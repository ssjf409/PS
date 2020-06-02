#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> visited; // 0 방문 안함, 1 점프 안할걸로 방문함, 2 점프로 방문함
vector<vector<int>> lastVal;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

struct State {
    int y, x, max;
    bool canJump;

    State(int y_, int x_, int max_, bool canJump_) : y(y_), x(x_), max(max_), canJump(canJump_) {}
};

// 큐 작은 거부터 꺼내기
// struct compare {
//     bool operator()(const State& a, const State& b) {

//         return a.max > b.max;
//     }
// };

int bfs() {
    // priority_queue<State, vector<State>, compare> pq;
    queue<State> q;
    visited[0][0] = 1;
    lastVal[0][0] = board[0][0];
    q.push(State(0, 0, board[0][0], true));

    // int ret = INF;

    while(!q.empty()) {
        State cur = q.front();
        q.pop();

        // cout << "==========\n";
        // for(const auto& el : lastVal) {
        //     for(const auto& e : el) {
        //         cout << e << ' ';
        //     }
        //     cout << '\n';
        // }

        if(cur.y == N - 1 && cur.x == M - 1) {
            return cur.max;
        }

        for(int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if(visited[ny][nx]) {
                // 가봐야 득될거 없으면 안 간다
                if(cur.canJump && visited[ny][nx] == 2) {
                    if(lastVal[ny][nx] < cur.max) continue;
                } else {
                    if(lastVal[ny][nx] <= cur.max) continue;
                }
                
            // 방문한 적 없을 때.
            } else {
                visited[ny][nx] = cur.canJump ? 1 : 2;
            }

            lastVal[ny][nx] = max(cur.max, board[ny][nx]);
            q.push(State(ny, nx, lastVal[ny][nx], cur.canJump));
        }

        if(cur.canJump) {
            for(int dir = 0; dir < 4; dir++) {
                int ny = cur.y + 2 * dy[dir];
                int nx = cur.x + 2 * dx[dir];

                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

                if(visited[ny][nx]) {
                    // 가봐야 득될거 없으면 안 간다.
                    if(lastVal[ny][nx] <= cur.max) continue;
                // 방문한 적 없을 때.
                } else {
                    visited[ny][nx] = 2;
                }
                lastVal[ny][nx] = max(cur.max, board[ny][nx]);
                q.push(State(ny, nx, lastVal[ny][nx], false));
            }

        }

    }

    return INF;

}


int main() {
    cin >> N >> M;

    board.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M, 0));
    lastVal.assign(N, vector<int>(M, INF));


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    cout << bfs();


    return 0;
}