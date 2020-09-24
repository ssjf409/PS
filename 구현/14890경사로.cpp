#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L;
vector<vector<int>> board;
int cnt = 0;

bool canInstallRoad(vector<pair<int, bool>>& spot) {

    vector<bool> installed(board.size(), false);

    for(int i = 0; i < spot.size(); i++) {
        int loc = spot[i].first;
        bool isRight = spot[i].second;

        if(isRight) {
            if(loc + L - 1 >= N) return false;
            for(int j = 0; j < L; j++) {
                if(installed[loc + j]) return false;
                installed[loc + j] = true;
            }
        } else {
            if(loc - L + 1 < 0) return false;
            for(int j = 0; j < L; j++) {
                if(installed[loc - j]) return false;
                installed[loc - j] = true;
            }
        }
    }
    return true;
}

bool canMakeRow(int n) {
    
    // location, isRight
    vector<pair<int, bool>> spot;
    for(int i = 1; i < board[n].size(); i++) {
        if(board[n][i - 1] + 1 == board[n][i]) {
            spot.push_back({i - 1, false});
        } else if(board[n][i - 1] == board[n][i] + 1) {
            spot.push_back({i, true});
        } else if(abs(board[n][i - 1] - board[n][i]) >= 2) {
            return false;
        }
    }

    return canInstallRoad(spot);
}

bool canMakeCol(int n) {
    
    // location, isRight
    vector<pair<int, bool>> spot;
    for(int i = 1; i < board.size(); i++) {
        if(board[i - 1][n] + 1 == board[i][n]) {
            spot.push_back({i - 1, false});
        } else if(board[i - 1][n] == board[i][n] + 1) {
            spot.push_back({i, true});
        } else if(abs(board[i - 1][n] - board[i][n]) >= 2) {
            return false;
        }
    }

    return canInstallRoad(spot);
}

int main() {
    cin >> N >> L;
    board.assign(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        if(canMakeRow(i)) cnt++;
    }

    
    for(int i = 0; i < N; i++) {
        if(canMakeCol(i)) cnt++;
    }

    cout << cnt;
    
    return 0;
}