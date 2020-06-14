#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N;

vector<vector<char>> board;
vector<vector<bool>> visited;

vector<int> lands;

void bfs(int y, int x) {
    if(visited[y][x]) return;
    if(board[y][x] == 'W') {
        visited[y][x] = true;
        return;
    }
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    int cnt = 0;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        cnt++;
        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(visited[ny][nx] || board[ny][nx] == 'W') continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    lands.push_back(cnt);
}

int main() {
    cin >> N;
    board.assign(N, vector<char>(N));
    visited.assign(N, vector<bool>(N, false));
    
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < N; j++) {
            board[i][j] = str[j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            bfs(i, j);
        }
    }

    sort(lands.begin(), lands.begin());


    if(lands.size() == 1) {
        cout << "0 0 0.00 0\n";
    } else {
        int index = 0;
        int biggest = lands[0];

        bool beingIsland = false;
        for(int i = 0; i < lands.size(); i++) {
            if(biggest > lands[i]) {
                beingIsland = true;
                index = i;
                break;
            }
        }

        if(beingIsland) {
            int bigIsland = lands[index];
            int smallIsland = lands[lands.size() - 1];

            double sum = 0.0;
            int cnt = 0;
            for(int i = index; i < lands.size(); i++) {
                sum += lands[i];
                cnt++;
            }
            double avg = sum / cnt;

            cout << bigIsland << ' ' << smallIsland << ' ';
            printf("%.2lf ", avg);

            int temp = index + lands.size() - 1;
            
            // 중앙값 2개
            if(temp % 2 == 1) {
                double mid = (lands[temp / 2] + lands[temp / 2 + 1]) / 2.0;
                printf("%.2lf\n", mid);
            } else {
                cout << lands[temp / 2] << endl;;
            }

        } else {
            cout << "0 0 0.00 0\n";
        }
    }
    


	return 0;
}