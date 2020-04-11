#include <iostream>
#define MAX 14

using namespace std;

int N, sum;
int board[MAX + 1][MAX + 1];

const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void setQueen(int row, int col, int cover) {
    int tempRow;
    int tempCol;
    board[row][col] += cover;
    for(int dir = 0; dir < 8; dir++) {
        for(int length = 1; length < N; length++) {
            tempRow = row + length * dy[dir];
            tempCol = col + length * dx[dir];
            if(tempRow < 0 || tempRow >= N || tempCol < 0 || tempCol >= N) {
                break;
            }
            board[tempRow][tempCol] += cover;
        }
    }
}

void getCaseNum(int row) {
    if(row == N) {
        sum++;
        return;
    }
    for(int col = 0; col < N; col++) {
        if(!board[row][col]) {
            setQueen(row, col, 1);
            getCaseNum(row + 1);
            setQueen(row, col, -1);
        }
    }
}

int main() {
    cin >> N;
    getCaseNum(0);
    cout << sum;
    return 0;
}