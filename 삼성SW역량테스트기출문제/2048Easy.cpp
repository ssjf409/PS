#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N;
int result = 0;

void move(vector<vector<int>>& board, int dir) {

    vector<queue<int>> q(N);
    vector<int> indexs;

    switch(dir) {
        case 0:
            indexs.assign(N, 0);
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    int& index = indexs[j];
                    if(q[j].empty()) {
                        q[j].push(board[i][j]);
                        continue;
                    }
                    if(q[j].front() == board[i][j]) {
                        board[index++][j] = board[i][j] * 2;
                        board[i][j] = 0;
                        q[j].pop();
                    } else {
                        board[index++][j] = q[j].front();
                        q[j].push(board[i][j]);
                        q[j].pop();
                    }
                }
            }
            for(int j = 0; j < N; j++) {
                int& index = indexs[j];
                if(index != N) {
                    if(!q[j].empty()) {
                        board[index++][j] = q[j].front();
                        q[j].pop();
                    }
                    while(index != N) {
                        board[index++][j] = 0;
                    }
                }
            }
        break;

        case 1:
            indexs.assign(N, N - 1);
            for(int i = N - 1; i >= 0; i--) {
                for(int j = N - 1; j >= 0; j--) {
                    int& index = indexs[j];
                    if(q[j].empty()) {
                        q[j].push(board[i][j]);
                        continue;
                    }
                    if(q[j].front() == board[i][j]) {
                        board[index--][j] = board[i][j] * 2;
                        board[i][j] = 0;
                        q[j].pop();
                    } else {
                        board[index--][j] = q[j].front();
                        q[j].push(board[i][j]);
                        q[j].pop();
                    }
                }
            }
            for(int j = 0; j < N; j++) {
                int& index = indexs[j];
                if(index >= 0) {
                    if(!q[j].empty()) {
                        board[index--][j] = q[j].front();
                        q[j].pop();
                    }
                    while(index >= 0) {
                        board[index--][j] = 0;
                    }
                }
            }

        break;

        case 2:
            indexs.assign(N, 0);
            for(int j = 0; j < N; j++) {
                for(int i = 0; i < N; i++) {
                    int& index = indexs[i];
                    if(q[i].empty()) {
                        q[i].push(board[i][j]);
                        continue;
                    }
                    if(q[i].front() == board[i][j]) {
                        board[i][index++] = board[i][j] * 2;
                        board[i][j] = 0;
                        q[i].pop();
                    } else {
                        board[i][index++] = q[i].front();
                        q[i].push(board[i][j]);
                        q[i].pop();
                    }
                }
            }
            for(int i = 0; i < N; i++) {
                int& index = indexs[i];
                if(index != N) {
                    if(!q[i].empty()) {
                        board[i][index++] = q[i].front();
                        q[i].pop();
                    }
                    while(index != N) {
                        board[i][index++] = 0;
                    }
                }
            }

        break;
        case 3:
            indexs.assign(N, N - 1);
            for(int j = N - 1; j >= 0; j--) {
                for(int i = N - 1; i >= 0; i--) {
                    int& index = indexs[i];
                    if(q[i].empty()) {
                        q[i].push(board[i][j]);
                        continue;
                    }
                    if(q[i].front() == board[i][j]) {
                        board[i][index--] = board[i][j] * 2;
                        board[i][j] = 0;
                        q[i].pop();
                    } else {
                        board[i][index--] = q[i].front();
                        q[i].push(board[i][j]);
                        q[i].pop();
                    }
                }
            }
            for(int i = 0; i < N; i++) {
                int& index = indexs[i];
                if(index >= 0) {
                    if(!q[i].empty()) {
                        board[i][index--] = q[i].front();
                        q[i].pop();
                    }
                    while(index >= 0) {
                        board[i][index--] = 0;
                    }
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

    // move(board, 3);

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    dfs(board, 0);

    cout << result;

    return 0;
}