#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int N, M, K;

vector<vector<int>> board;


struct Dice {
    int north;
    int west;
    int top;
    int east;
    int south;
    int bottom;
    Dice() {
        north = west = top = east = south = bottom = 0;
    }

    void moveNorth() {
        int temp = top;
        top = south;
        south = bottom;
        bottom = north;
        north = temp;
    }

    
    void moveWest() {
        int temp = top;
        top = east;
        east = bottom;
        bottom = west;
        west = temp;
    }

    void moveEast() {
        int temp = top;
        top = west;
        west = bottom;
        bottom = east;
        east = temp;
    }

    void moveSouth() {
        int temp = top;
        top = north;
        north = bottom;
        bottom = south;
        south = temp;
    }

};


int main() {
    int y, x;
    cin >> N >> M >> y >> x >> K;

    board.assign(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    Dice dice;

    int cmd;
    for(int i = 0; i < K; i++) {
        cin >> cmd;
        int ny = y + dy[cmd - 1];
        int nx = x + dx[cmd - 1];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

        y = ny;
        x = nx;
        switch(cmd) {
            case 1:
                dice.moveEast();
            break;
            case 2:
                dice.moveWest();
            break;
            case 3:
                dice.moveNorth();
            break;
            case 4:
                dice.moveSouth();
            break;
        }

        if(board[y][x] == 0) {
            board[y][x] = dice.bottom;
        } else {
            dice.bottom = board[y][x];
            board[y][x] = 0;
        }

        cout << dice.top << '\n';
    }


    
    
    return 0;
}