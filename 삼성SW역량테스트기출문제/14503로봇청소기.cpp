#include <iostream>
#include <vector>
#define CLEAN 2

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M;

vector<vector<int>> board;

int main() {
    cin >> N >> M;

    board.assign(N, vector<int>(M));

    int y, x, dir;
    cin >> y >> x >> dir;


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int cleanCnt = 0;
    int leftCnt = 0;
    bool one_flag = true;

    while(true) {
        if(leftCnt == 4) {
            int temp_y = y - dy[dir];
            int temp_x = x - dx[dir];
            if(temp_y < 0 || temp_y >= N || temp_x < 0 || temp_x >= M || board[temp_y][temp_x] == 1) {
                break;
            } else {
                y = temp_y;
                x = temp_x;
                one_flag = false;
                leftCnt = 0;
            }
        }


        if(one_flag) {
            cleanCnt++;
            board[y][x] = CLEAN;
        }

        
        int ndir = (dir + 3) % 4;
        int ny = y + dy[ndir];
        int nx = x + dx[ndir];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] == 1 || board[ny][nx] == CLEAN) {
            dir = ndir;
            one_flag = false;
            leftCnt++;
            continue;
        }

        if(board[ny][nx] == 0) {
            dir = ndir;
            y = ny;
            x = nx;
            one_flag = true;
            leftCnt = 0;
            continue;
        }

    }

    cout << cleanCnt;


    return 0;
}