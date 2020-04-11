#include <iostream>
#include <vector>

using namespace std;

const int knightDx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int knightDy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};


int main() {

    int N;
    vector<vector<int>> board(N, vector<int>(N));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    

    return 0;
}