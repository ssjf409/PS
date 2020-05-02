#include <iostream>
#include <vector>
#include <queue>


using namespace std;


struct Point {
    int y;
    int x;
    Point(int a, int b) : y(a), x(b) {}
};

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int N, M, A, B, K;

vector<vector<int>> map;


bool canGo(int cy, int cx, int my, int mx) {
    if(my < 0 || mx < 0 || my + A >= N || mx + B >= M) return false;
    for(int i = my; i < my + A; i++) {
        for(int j = mx; j < mx + B; j++) {
            if(map[i][j] == -1) return false;
        }
    }

    return true;
}


int bfs(int sy, int sx, int ey, int ex) {

    Point p(sy, sx);

    queue<Point> q;

    q.push(p);

    int cnt = 0;
    map[sy][sx] = cnt;


    while(!q.empty()) {
        int qSize = q.size();
        cnt++;

        for(int i = 0; i < qSize; i++) {
            Point curPoint = q.front();
            
            q.pop();
            int y = curPoint.y;
            int x = curPoint.x;
            map[y][x] = cnt;

            for(int j = 0; j < N; j++) {
                for(int k = 0; k < M; k++) {
                    cout << map[j][k];
                }
                cout << '\n';
            }



            for(int dir = 0; dir < 4; dir++){
                int my = y + dy[dir];
                int mx = x + dx[dir];
                if(canGo(y, x, my, mx) && !map[my][mx]) {
                    q.push(Point(my, mx));
                }
            }
        }
    }
    return map[ey][ex];
}



int main() {
    cin >> N >> M >> A >> B >> K;
    map.assign(N, vector<int>(M, 0));

    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = -1;
    }

    int sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;

    int res = bfs(sy, sx, ey, ex);

    if(res == 0) {
        cout << -1;
    } else {
        cout << res;
    }
    

    return 0;
}