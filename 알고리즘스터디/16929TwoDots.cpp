#include <iostream>
#include <vector>


using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<vector<bool>> visiting;


bool findCircle(char color,int py, int px, int y, int x) {
    if(visiting[y][x]) return true;
    if(visited[y][x]) return false;
    visited[y][x] = true;
    visiting[y][x] = true;

    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(py == ny && px == nx) continue;
        if(board[ny][nx] != color) continue;
        if(findCircle(color, y, x, ny, nx)) return true;
    }
    visiting[y][x] = false;
    return false;
}

int main() {
    cin >> N >> M;

    board.assign(N, vector<char>(M));
    visited.assign(N, vector<bool>(M, false));
    visiting.assign(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }


    bool flag = false;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
                if(findCircle(board[i][j], -1, -1, i, j)) {
                    flag = true;
                    break;
                }
            // }
        }
        if(flag) break;
    }

    if(flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}