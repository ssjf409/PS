#include <iostream>
#include <queue>
#define MAX 9

// using namespace std;

int board[MAX][MAX];

bool getSudocu(int y, int x) {
    if(y == MAX) return true;
    if(x == MAX) return getSudocu(y + 1, 0);
    if(board[y][x]) return getSudocu(y, x + 1);
    
    
    bool visitNum[10] = {false,};
    int tempY = y / 3 * 3;
    int tempX = x / 3 * 3;

    // 가로찾기
    for(int i = 0; i < MAX; i++) {
        visitNum[board[y][i]] = true;
    }
    // 세로찾기
    for(int i = 0; i < MAX; i++) {
        visitNum[board[i][x]] = true;
    }
    // 사각형찾기
    for(int i = tempY; i < tempY + 3; i++) {
        for(int j = tempX; j < tempX + 3; j++) {
            visitNum[board[i][j]] = true;
        }
    }

    for(int i = 1; i <= MAX; i++) {
        if(visitNum[i]) continue;
        board[y][x] = i;
        if(getSudocu(y, x + 1)) return true;
    }
    board[y][x] = 0;
    return false;
}


int main() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            std::cin >> board[i][j];
        }
    }
    getSudocu(0, 0);

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
