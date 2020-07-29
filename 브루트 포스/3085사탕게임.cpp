#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N;
vector<vector<char>> board;

inline void change(int y, int x, int ny, int nx) {
    char temp = board[y][x];
    board[y][x] = board[ny][nx];
    board[ny][nx] =  temp;
}

int getCandyCnt(int y, int x) {
    char pickedColor = board[y][x];
    int colCnt = 1;
    int rowCnt = 1;

    for(int i = 1; y + i < N && pickedColor == board[y + i][x]; i++) {
        colCnt++;
    }
    for(int i = 1; y - i >= 0 && pickedColor == board[y - i][x]; i++) {
        colCnt++;
    }

    for(int i = 1; x + i < N && pickedColor == board[y][x + i]; i++) {
        rowCnt++;
    }
    for(int i = 1; x - i >= 0 && pickedColor == board[y][x - i]; i++) {
        rowCnt++;
    }
    return max(colCnt, rowCnt);
}

inline int getMaxCandy(int y, int x) {
    int maxCandy = 0;
    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        change(y, x, ny, nx);
        int count = getCandyCnt(y, x);
        if(count > maxCandy) {
            maxCandy = count;
        }
        change(y, x, ny, nx);
    }

    return maxCandy;
}

int main() {
    cin >> N;

    board.assign(N, vector<char>(N, ' ' ));


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int maxCnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cnt = getMaxCandy(i, j);
            if(cnt > maxCnt) {
                maxCnt = cnt;
            }
        }
    }
    cout << maxCnt;

    return 0;
}