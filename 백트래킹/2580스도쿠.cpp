#include <iostream>
#define MAX 9

// using namespace std;

// struct PointState {
//     int y;
//     int x;
//     int num;
//     PointState(int i, int j, int n) : y(i), x(j), num(n) {}
// };

int board[MAX][MAX];

bool checkRow(int row) {
    bool visit[9] = {false,};
    int x;

    for(int i = 0; i < MAX; i++) {
        if(board[row][i] == 0) {
            x = i;
        } else {
            visit[board[row][i] - 1] = true;
        }
    }
    int cnt = 0;
    int index = 0;
    for(int i = 0; i < MAX; i++) {
        if(visit[i]) {
            cnt++;
        } else {
            index = i;
        }
    }
    if(cnt == 8) {
        board[row][x] = index + 1;
        return true;
    } else {
        return false;
    }
}

bool checkCol(int col) {
    bool visit[9] = {false,};
    int y;

    for(int i = 0; i < MAX; i++) {
        if(board[i][col] == 0) {
            y = i;
        } else {
            visit[board[i][col] - 1] = true;
        }
    }
    int cnt = 0;
    int index = 0;
    for(int i = 0; i < MAX; i++) {
        if(visit[i]) {
            cnt++;
        } else {
            index = i;
        }
    }
    if(cnt == 8) {
        board[y][col] = index + 1;
        return true;
    } else {
        return false;
    }
}


bool checkSqu(int y, int x) {
    bool visit[9] = {false,};
    int tempy, tempx;

    for(int i = y; i < y + 3; i++) {
        for(int j = x ; j < x + 3; j++) {
            if(board[i][j] == 0) {
                tempy = i;
                tempx = j;
            } else {
                visit[board[i][j] - 1] = true;
            }
        }
    }
    int cnt = 0;
    int index = 0;
    for(int i = 0; i < MAX; i++) {
        if(visit[i]) {
            cnt++;
        } else {
            index = i;
        }
    }
    if(cnt == 8) {
        board[tempy][tempx] = index + 1;
        return true;
    } else {
        return false;
    }
}


int main() {
    int cnt = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 0) cnt++;
        }
    }

    while(true) {
        int rvalue;
        int cvalue;
        int svalue;
        for(int i = 0; i < MAX; i++) {
            if(checkRow(i)) cnt--;
        }
        for(int i = 0; i < MAX; i++) {
            if(checkCol(i)) cnt--;
        }
        for(int i = 0; i < MAX; i +=3) {
            for(int j = 0; j < MAX; j +=3) {
                if(checkSqu(i, j)) cnt--;
            }
        }
        if(cnt == 0) break;
    }
    // std::cout << "===================\n";
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

