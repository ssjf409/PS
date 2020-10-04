#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

int bfs(const vector<pair<int, int>>& virus) {
    visited.assign(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    int cnt = 0;

    for(int i = 0; i < virus.size(); i++) {
        q.push({virus[i].first, virus[i].second});
        visited[virus[i].first][virus[i].second] = true;
    }

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        cnt++;

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(board[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }


    }



    return cnt;
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    vector<pair<int, int>> virus;
    int cnt = 0;
    int max = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                virus.push_back({i, j});
            } else if(board[i][j] == 1) {
                cnt++;
            }
        }
    }

    for(int i = 0; i < N * M - 2; i++) {
        for(int j = i + 1; j < N * M - 1; j++) {
            for(int k = j + 1; k < N * M; k++) {
                int ay = i / M;
                int ax = i % M;
                int by = j / M;
                int bx = j % M;
                int cy = k / M;
                int cx = k % M;
                if(board[ay][ax] || board[by][bx] || board[cy][cx]) continue;
                board[ay][ax] = board[by][bx] = board[cy][cx] = 1;
                int virusCnt = bfs(virus);
                board[ay][ax] = board[by][bx] = board[cy][cx] = 0;
                int remainder = N * M - cnt - virusCnt - 3;
                if(remainder > max) {
                    max = remainder;
                }
            }
        }
    }


    cout << max;

    return 0;
}