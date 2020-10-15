#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N;
int result = 0;

void move(vector<vector<int>>& board, int dir) {

    vector<int> prev(N);
    vector<int> index;
    vector<bool> preserved(N, false);

    switch(dir) {
        case 0:
            index.assign(N, 0);
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(board[i][j] == 0) continue;
                    if(!preserved[j]) {
                        preserved[j] = true;
                        prev[j] = board[i][j];
                        continue;
                    }
                    if(prev[j] == board[i][j]) {
                        board[index[j]++][j] = prev[j] * 2;
                        preserved[j] = false;
                    } else {
                        board[index[j]++][j] = prev[j];
                        prev[j] = board[i][j];
                    }
                }
            }
            for(int j = 0; j < N; j++) {
                if(preserved[j]) {
                    preserved[j] = false;
                    board[index[j]++][j] = prev[j];
                }
                while(index[j] != N) {
                    board[index[j]++][j] = 0;
                }
            }
        break;
        
        case 1:
            index.assign(N, N - 1);
            for(int i = N - 1; i >= 0; i--) {
                for(int j = 0; j < N; j++) {
                    if(board[i][j] == 0) continue;
                    if(!preserved[j]) {
                        preserved[j] = true;
                        prev[j] = board[i][j];
                        continue;
                    }
                    if(prev[j] == board[i][j]) {
                        board[index[j]--][j] = prev[j] * 2;
                        preserved[j] = false;
                    } else {
                        board[index[j]--][j] = prev[j];
                        prev[j] = board[i][j];
                    }
                }
            }
            for(int j = 0; j < N; j++) {
                if(preserved[j]) {
                    preserved[j] = false;
                    board[index[j]--][j] = prev[j];
                }
                while(index[j] >= 0) {
                    board[index[j]--][j] = 0;
                }
            }

        break;
        case 2:
            index.assign(N, 0);
            for(int j = 0; j < N; j++) {
                for(int i = 0; i < N; i++) {
                    if(board[i][j] == 0) continue;
                    if(!preserved[i]) {
                        preserved[i] = true;
                        prev[i] = board[i][j];
                        continue;
                    }
                    if(prev[i] == board[i][j]) {
                        board[i][index[i]++] = prev[i] * 2;
                        preserved[i] = false;
                    } else {
                        board[i][index[i]++] = prev[i];
                        prev[i] = board[i][j];
                    }
                }
            }
            for(int i = 0; i < N; i++) {
                if(preserved[i]) {
                    preserved[i] = false;
                    board[i][index[i]++] = prev[i];
                }
                while(index[i] != N) {
                    board[i][index[i]++] = 0;
                }
            }

        break;
        case 3:
            index.assign(N, N - 1);
            for(int j = N - 1; j >= 0; j--) {
                for(int i = 0; i < N; i++) {
                    if(board[i][j] == 0) continue;
                    if(!preserved[i]) {
                        preserved[i] = true;
                        prev[i] = board[i][j];
                        continue;
                    }
                    if(prev[i] == board[i][j]) {
                        board[i][index[i]--] = prev[i] * 2;
                        preserved[i] = false;
                    } else {
                        board[i][index[i]--] = prev[i];
                        prev[i] = board[i][j];
                    }
                }
            }
            for(int i = 0; i < N; i++) {
                if(preserved[i]) {
                    preserved[i] = false;
                    board[i][index[i]--] = prev[i];
                }
                while(index[i] >=0) {
                    board[i][index[i]--] = 0;
                }
            }

        break;
    }

}

void dfs(vector<vector<int>>& board, int cur) {



    if(cur == 5) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] > result) {
                    result = board[i][j];
                }
            }
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        vector<vector<int>> temp = board;
        move(temp, i);
        dfs(temp, cur + 1);
    }
}


int main() {
    cin >> N;
    vector<vector<int>> board;

    board.assign(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(board, 0);

    cout << result;


    return 0;
}