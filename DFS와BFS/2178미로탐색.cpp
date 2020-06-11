#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

int bfs(int y, int x) {
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    int ret = 0;

    while(!q.empty()) {
        int qSize = q.size();
        ret++;
        for(int i = 0; i < qSize; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            if(cy == N - 1 && cx == M - 1) return ret;

            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(visited[ny][nx]) continue;
                if(board[ny][nx] == 0) continue;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    cout << bfs(0, 0);

    return 0;
}