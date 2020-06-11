#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N;
int comNum = 0;

vector<vector<int>> board;
vector<vector<bool>> visited;

int bfs(int y, int x) {
    if(visited[y][x] || board[y][x] == 0) return 0;
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    comNum++;
    int ret = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(board[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            ret++;
            q.push({ny, nx});
        }


    }

    return ret;
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));
    vector<int> buildingNum;

    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < N; j++) {
            board[i][j] = str[j] - '0';
        }
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int temp = bfs(i, j);
            if(temp > 0) {
                buildingNum.push_back(temp);
            }
        }
    }


    sort(buildingNum.begin(), buildingNum.end());

    cout << comNum << '\n';
    for(const auto& el : buildingNum) {
        cout << el << '\n';
    }
    return 0;
}