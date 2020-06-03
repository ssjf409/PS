#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;


int K, W, H;

vector<vector<int>> board;
// vector<vector<int>> visited;

int visited[201][201][31];

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

const int ndy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ndx[8] = {1, 2, 2, 1, -1, -2, -2, -1};



int bfs() {
    queue<pair<int, pair<int, pair<int, int>>>> q;

    visited[0][0][K] = 0;
    // max, k, y, x
    q.push({0, {K, {0, 0}}});

    while(!q.empty()) {
        int cmax = -q.front().first;
        int ck = q.front().second.first;
        int cy = q.front().second.second.first;
        int cx = q.front().second.second.second;
        q.pop();

        // for(int i = 0; i < H; i++) {
        //     for(int j = 0; j < W; j++) {
        //         cout << visited[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }


        if(cy == H - 1 && cx == W - 1) {
            return cmax;
        }

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(visited[ny][nx][ck] != -1) continue;
            if(board[ny][nx] == 1) continue;
            visited[ny][nx][ck] = cmax + 1;
            q.push({-cmax-1, {ck, {ny, nx}}});
        }

        if(ck > 0) {
            for(int dir = 0; dir < 8; dir++) {
                int ny = cy + ndy[dir];
                int nx = cx + ndx[dir];

                if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if(visited[ny][nx][ck - 1] != -1) continue;
                if(board[ny][nx] == 1) continue;
                visited[ny][nx][ck - 1] = cmax + 1;
                q.push({-cmax-1, {ck - 1, {ny, nx}}});
            }
        }




    }

    return -1;

}


int main() {
    cin >> K >> W >> H;
    board.assign(H, vector<int>(W));
    // visited.assign(H, vector<int>(W, INF));

    
    memset(visited, -1, sizeof(visited));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    cout << bfs();

    




    return 0;
}