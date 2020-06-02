#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define INF 987654321

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pair<int, bool>> val;
vector<pair<int, bool>>::iterator iter;

vector<pair<int, int>> path;

int ret = INF;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};


bool canSkip(const int& ny, const int& nx) {
    int py = path[path.size() - 2].first;
    int px = path[path.size() - 2].second;
    if(abs(ny - py) >= 2) return false;
    if(abs(nx - px) >= 2) return false;
    return true;
}


void rec(int y, int x) {
    if(y == 0 && x == 0) visited[0][0] = true;
    
    if(y == N - 1 && x == M - 1) {


        int temp;
        if(val[val.size() - 1].second == false) {
            temp = val[val.size() - 2].first;
        } else {
            temp = val[val.size() - 1].first;
        }

        if(temp < ret) ret = temp;


        
        return;
    }

    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx]) continue;

        visited[ny][nx] = true;

        bool isCur = canSkip(ny, nx);


        iter = lower_bound(val.begin(), val.end(), make_pair(board[ny][nx], isCur));
        val.insert(iter, {board[ny][nx], isCur});
        path.push_back({ny, nx});
        


        rec(ny, nx);
        iter = lower_bound(val.begin(), val.end(), make_pair(board[ny][nx], isCur));
        val.erase(iter);
        path.pop_back();

        visited[ny][nx] = false;


    }
}




int main() {
    cin >> N >> M;

    board.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    val.push_back({board[0][0], false});
    path.push_back({0, 0});
    path.push_back({0, 0});
    rec(0, 0);


    cout << ret;

    return 0;
}