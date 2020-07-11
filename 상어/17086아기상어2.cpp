#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

int bfs(int y, int x) {
    if(board[y][x]) return 0;
    visited.assign(N, vector<bool>(M, false));
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    int step = 0;

    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            for(int dir = 0; dir < 8; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(visited[ny][nx]) continue;
                if(board[ny][nx]) return step + 1;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        step++;
    }
    return step;
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int maxLen = -1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int temp = bfs(i, j);
            if(temp > maxLen) maxLen = temp;
        }
    }
    
    cout << maxLen;

    return 0;
}