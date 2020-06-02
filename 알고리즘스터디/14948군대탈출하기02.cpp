#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> node;


int N, M;
int board[101][101];
bool visited[101][101];
int bVal[101][101][2];

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

const int dy2[5] = {0, 0, 0, -2, 2};
const int dx2[5] = {0, -2, 2, 0, 0};

inline int max(const int a, const int b) {
    return a > b ? a : b;
}


inline int min(const int a, const int b) {
    return a < b ? a : b;
}

void scan(const int y, const int x, const bool canJump) {
    priority_queue<node> pq;
    int maxVal = board[y][x];

    memset(visited, false, sizeof(visited));

    bVal[y][x][canJump] = board[y][x];
    visited[y][x] = true;
    
    pq.push({-board[y][x], {y, x}});

    while(!pq.empty()) {
        node cur = pq.top();
        pq.pop();

        int cmax = -cur.first;
        int cy = cur.second.first;
        int cx = cur.second.second;

        if(maxVal < cmax) maxVal = cmax;
        bVal[cy][cx][canJump] = maxVal;

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            pq.push({-board[ny][nx], {ny, nx}});
        }
    }
}



int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    

    scan(0, 0, true);

    scan(N - 1, M - 1, false);

    int ans = -1;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            for(int dir = 0; dir < 5; dir++) {
                int ny = y + dy2[dir];
                int nx = x + dx2[dir];

                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

                int cand = max(bVal[y][x][true], bVal[ny][nx][false]);
                if(ans == -1 || ans > cand) ans = cand;
            }
        }
    }

    cout << ans;

    return 0;
}