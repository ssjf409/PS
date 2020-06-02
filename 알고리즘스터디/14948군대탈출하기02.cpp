#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define INF 987654321

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

struct State {
    int y, x, max;
    int dir;
    bool canJump;

    State(int y_, int x_, int max_, int dir_, bool canJump_) : y(y_), x(x_), max(max_), dir(dir_), canJump(canJump_) {}
};

int N, M;
vector<vector<int>> board;
vector<vector<vector<int>>> visited; // y, x, canJump(bool) : 점프 사용한 거랑 안한거랑 구별해서 값 저장한다.


// 큐 작은 거부터 꺼내기
struct compare {
    bool operator()(const State& a, const State& b) {
        return a.max > b.max;
    }
};

int bfs() {
    priority_queue<State, vector<State>, compare> pq;

    visited[0][0][true] = board[0][0];
    // 맨처음은 방향이 없으므로 4를 준다.
    pq.push(State(0, 0, board[0][0], 4, true));

    while(!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int cy = cur.y;
        int cx = cur.x;
        int cdir = cur.dir;
        bool ccanJump = cur.canJump;
        int cmax = cur.max;


        // 같은 상태로 방문한 적 있고, 이전 값이 더 낮다면 더해볼 필요가 없다.
        if(visited[cy][cx][ccanJump] != -1 && visited[cy][cx][ccanJump] < cmax) continue;


        // 방문한적 없으면 방문체크
        // 우선순위 큐로 방문 했기 때문에 가장 맨처음 방문 했을 때가 최소 경로로 온 경우다.
        visited[cy][cx][ccanJump] = cmax;

        if(cur.y == N - 1 && cur.x == M - 1) {
            return cmax;
        }

        

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx][ccanJump] != -1) continue;
            
            pq.push(State(ny, nx, max(cmax, board[ny][nx]), dir, ccanJump));


            // 점프 할 수 있고, 같은 방향일 때만
            if(!ccanJump) continue;


            ny += dy[dir];
            nx += dx[dir];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx][ccanJump] != -1) continue;

            pq.push(State(ny, nx, max(cmax, board[ny][nx]), dir, false));

        }
    }

    return INF;
}


int main() {
    cin >> N >> M;

    board.assign(N, vector<int>(M));
    // memset(visited, -1, sizeof(visited));
    
    // [N][M][2] : -1로 초기화
    visited.assign(N, vector<vector<int>>(M, vector<int>(2, -1)));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    cout << bfs();


    return 0;
}