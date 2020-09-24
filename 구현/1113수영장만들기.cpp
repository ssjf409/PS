#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<bool>> counted;

int bfs(int y, int x, int high) {
    if(visited[y][x]) return 0;
    visited[y][x] = true;
    if(board[y][x] > high) return 0;

    queue<pair<int, int>> q;
    q.push({y, x});

    int ret = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) return 0;
            if(board[ny][nx] > high) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            ret++;
            q.push({ny, nx});
        }

    }

    return ret;
}

int main() {
    cin >> N >> M;

    board.assign(N, vector<int>(M));
    counted.assign(N, vector<bool>(M, false));

    int maxHigh = 0;
    char c;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> c;
            board[i][j] = c - '0';
            if(board[i][j] > maxHigh) {
                maxHigh = board[i][j];
            }
        }
    }


    int water = 0;
    for(int high = 1; high < maxHigh; high++) {
        visited.assign(N, vector<bool>(M, false));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                water += bfs(i, j, high);
            }
        }
    }

    cout << water;

    return 0;
}