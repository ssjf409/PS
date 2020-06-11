#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited[2];

int getShortestDist(int y, int x) {
    queue<pair<bool, pair<int, int>>> q;
    visited[0][y][x] = true;
    visited[1][y][x] = true;

    // canBreakWall, y, x
    q.push({true, {y, x}});

    int ret = 0;

    while(!q.empty()) {
        int qSize = q.size();
        ret++;
        for(int i = 0; i < qSize; i++) {
            bool canBreak = q.front().first;
            int cy = q.front().second.first;
            int cx = q.front().second.second;
            q.pop();

            if(cy == N - 1 && cx == M - 1) return ret;

            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(visited[canBreak][ny][nx]) continue;
                if(!board[ny][nx]) {
                    visited[canBreak][ny][nx] = true;
                    q.push({canBreak, {ny, nx}});

                } else if(canBreak) {
                    visited[false][ny][nx] = true;
                    q.push({false, {ny, nx}});
                }
            }

        }
    }
    return -1;
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    visited[0].assign(N, vector<bool>(M, false));
    visited[1].assign(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    cout << getShortestDist(0, 0);

    return 0;
}