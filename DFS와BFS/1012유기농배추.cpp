#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

bool bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int y, int x) {
    if(visited[y][x] || board[y][x] == 0) return false;
    int N = board.size();
    int M = board[0].size();
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;
            if(!board[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }

    }




    return true;
}


int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int a, b;
        for(int j = 0; j < K; j++) {
            cin >> b >> a;
            board[a][b] = 1;
        }

        int cnt = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(bfs(board, visited, j, k)) cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}