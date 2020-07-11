#include <iostream>
#include <vector>
#define SHARK -2

using namespace std;

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void moveFishs(vector<vector<pair<int, int>>>& board, vector<pair<int, int>>& fishs) {
    for(int i = 1; i <= 16; i++) {
        if(fishs[i].first == -1) continue;
        int cy = fishs[i].first;
        int cx = fishs[i].second;
        int tempA, tempB;
        int ny, nx;
        for(int j = 0; j < 8; j++) {
            int ny = cy + dy[board[cy][cx].second];
            int nx = cx + dx[board[cy][cx].second];

            if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || board[ny][nx].first == SHARK) {
                board[cy][cx].second = (board[cy][cx].second + 1) % 8; 
                continue; 
            }
            int nFish = board[ny][nx].first;

            tempA = board[ny][nx].first;
            tempB = board[ny][nx].second;
            board[ny][nx].first = board[cy][cx].first;
            board[ny][nx].second = board[cy][cx].second;
            board[cy][cx].first = tempA;
            board[cy][cx].second = tempB;

            tempA = fishs[i].first;
            tempB = fishs[i].second;
            fishs[i].first = fishs[nFish].first;
            fishs[i].second = fishs[nFish].second;
            fishs[nFish].first = tempA;
            fishs[nFish].second = tempB;

            break;
        }
    }
}


int getMax(vector<vector<pair<int, int>>> board, vector<pair<int, int>> fishs, int y, int x) {
    int ret = 0;

    moveFishs(board, fishs);

    int fishFirst, fishSecond, boardFirst, boardSecond;

    for(int i = 1; i <= 3; i++) {
        int ny = y + dy[board[y][x].second] * i;
        int nx = x + dx[board[y][x].second] * i;
        if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        if(board[ny][nx].first == 0) continue;

        fishFirst = fishs[board[ny][nx].first].first;
        fishSecond = fishs[board[ny][nx].first].second;
        fishs[board[ny][nx].first] = {-1, -1};
        boardFirst = board[ny][nx].first;
        boardSecond = board[ny][nx].second;
        board[ny][nx] = {SHARK, board[y][x].second};
        board[y][x].first = 0;

        ret += getMax(board, fishs, ny, nx);

        fishs[board[ny][nx].first] = {fishFirst, fishSecond};
        board[ny][nx] = {boardFirst, boardSecond};
        board[y][x].first = SHARK;

    }
    

    return ret;
}


int main() {
    vector<vector<pair<int, int>>> board(4, vector<pair<int, int>>(4, pair<int, int>()));
    // i, j
    vector<pair<int, int>> fishs(17, pair<int, int>());

    int a, b;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            cin >> a >> b;
            board[i][j] = {a, b - 1};
            fishs[a] = {i, j};
        }
    }

    int temp = fishs[board[0][0].first].first;
    fishs[board[0][0].first] = {-1, -1};
    board[0][0].first = SHARK;

    cout << getMax(board, fishs, 0, 0) + temp;

    return 0;
}