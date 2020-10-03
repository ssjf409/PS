#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, -1};


int H, W;
vector<vector<int>> board;
vector<vector<bool>> visited;


int getSurface(int y, int x) {
    int cnt = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int ny = y + i;
            int nx = x + j;
            if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) continue;
            if(board[ny][nx] == 0) cnt++;            
        }
    }

    return cnt;
}

int main() {
    cin >> H >> W;
    board.assign(H, vector<int>(W, 0));
    visited.assign(H, vector<bool>(W, false));

    queue<pair<int, int>> q;

    char c;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> c;
            if(c == '.') {
                board[i][j] = 0;
            } else {
                board[i][j] = c - '0';
            }
        }
    }

    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(getSurface(i, j) >= board[i][j]) {
                q.push({i, j});
            }
        }
    }

    int cnt = 0;

    while(!q.empty()) {
        int qSize = q.size();
        queue<pair<int, int>> temp = q;
        for(int i = 0; i < qSize; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            board[cy][cx] = 0;
        }

        for(int k = 0; k < qSize; k++) {
            int cy = temp.front().first;
            int cx = temp.front().second;
            temp.pop();

            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int ny = cy + i;
                    int nx = cx + j;
                    if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) continue;
                    if(visited[ny][nx]) continue;
                    if(board[ny][nx] != 0 && getSurface(ny, nx) >= board[ny][nx]) {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }

        cnt++;
    }


    cout << cnt;

    return 0;
}