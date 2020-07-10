#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int maxLen = 0;
int h, w;

vector<string> board;
vector<vector<bool>> visited;

void bfs(int y, int x) {
    if(board[y][x] == 'W') return;
    visited[y][x] = true;
    queue<pair<int, pair<int, int>>> q;
    q.push({0 ,{y, x}});

    while(!q.empty()) {
        int cstep = q.front().first;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();

        if(cstep > maxLen) {
            maxLen = cstep;
        }

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == 'W') continue;
            visited[ny][nx] = true;
            q.push({cstep + 1, {ny, nx}});
        }
    }
}

int main() {
    cin >> h >> w;
    board.assign(h, "");

    for(int i = 0; i < h; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            visited.assign(h, vector<bool>(w, false));
            bfs(i, j);
        }
    }

    cout << maxLen;

    return 0;
}