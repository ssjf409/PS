#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

const int rot_dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int rot_dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N;

vector<vector<int>> board;
vector<vector<vector<bool>>> visited;

bool canRotation(int y, int x) {
    if(y < 1 || y >= N - 1 || x < 1 || x >= N - 1) return false;

    for(int i = 0; i < 8; i++) {
        if(board[y + rot_dy[i]][x + rot_dx[i]]) return false;
    }

    return true;
}

bool canMove(int y, int x, bool isRow) {

    for(int i = -1; i <= 1; i++) {
        if(board[y + i * !isRow][x + i * isRow]) return false;
    }

    return true;
}


int bfs(int sy, int sx, bool sIsRow, int ey, int ex, bool eIsRow) {
    // {{y, x}, isRow}
    queue<pair<pair<int, int>, bool>> q;
    q.push({{sy, sx}, sIsRow});
    visited[sy][sx][sIsRow] = true;

    int cnt = 0;

    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cy = q.front().first.first;
            int cx = q.front().first.second;
            int cIsRow = q.front().second;
            q.pop();

            if(cy == ey && cx == ex && cIsRow == eIsRow) return cnt;
            
            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny - !cIsRow < 0 || ny + !cIsRow >= N || nx - cIsRow < 0 || nx + cIsRow >= N) continue;
                if(!canMove(ny, nx, cIsRow)) continue;
                if(visited[ny][nx][cIsRow]) continue;

                visited[ny][nx][cIsRow] = true;
                q.push({{ny, nx}, cIsRow});
            }

            if(!visited[cy][cx][!cIsRow] && canRotation(cy, cx)) {
                visited[cy][cx][!cIsRow] = true;
                q.push({{cy, cx}, !cIsRow});
            }

        }

        cnt++;
    }

    return 0;
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<vector<bool>>(N, vector<bool>(2, false)));

    char c;
    int sy = 0;
    int sx = 0;
    bool sIsRow = false;
    int ey = 0;
    int ex = 0;
    bool eIsRow = false;
    for(int i = 0; i < N; i++) {
        bool sFlag = false;
        bool eFlag = false;
        for(int j = 0; j < N; j++) {
            cin >> c;
            if(c == 'B') {
                sy += i;
                sx += j;
                if(sFlag) {
                    sIsRow = true;
                }
                sFlag = true;
            } else if(c == 'E') {
                ey += i;
                ex += j;
                if(eFlag) {
                    eIsRow = true;
                }
                eFlag = true;
            } else if(c == '1') {
                board[i][j] = 1;
            }
        }
    }

    sy /= 3;
    sx /= 3;
    ey /= 3;
    ex /= 3;


    cout << bfs(sy, sx, sIsRow, ey, ex, eIsRow);

    return 0;
}