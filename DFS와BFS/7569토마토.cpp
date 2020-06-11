#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};

int N, M, H;
int zeroTomato = 0;
vector<vector<vector<int>>> board;
vector<vector<vector<bool>>> visited;

int bfs(const vector<pair<int, pair<int, int>>>& v) {
    queue<pair<int, pair<int, int>>> q;

    for(int i = 0; i < v.size(); i++) {
        int y = v[i].first;
        int x = v[i].second.first;
        int z = v[i].second.second;
        visited[y][x][z] = true;
        q.push({y, {x, z}});
    }

    int ret = 0;

    while(!q.empty()) {
        int qSize = q.size();

        if(zeroTomato == 0) return ret;
        ret++;
        for(int i = 0; i < qSize; i++) {
            int cy = q.front().first;
            int cx = q.front().second.first;
            int cz = q.front().second.second;
            q.pop();
            for(int dir = 0; dir < 6; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                int nz = cz + dz[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || nz < 0 || nz >= H) continue;
                if(visited[ny][nx][nz]) continue;
                if(board[ny][nx][nz] == 0) {
                    visited[ny][nx][nz] = true;
                    zeroTomato--;
                    q.push({ny, {nx, nz}});
                }
            }

        }

    }


    return -1;
}


int main() {

    cin >> M >> N >> H;
    board.assign(N, vector<vector<int>>(M, vector<int>(H, 0)));
    visited.assign(N, vector<vector<bool>>(M, vector<bool>(H, false)));
    vector<pair<int, pair<int, int>>> v;

    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == 0) zeroTomato++;
                else if(board[i][j][k] == 1) v.push_back({i, {j, k}});
            }
        }
    }

    cout << bfs(v);


    return 0;
}