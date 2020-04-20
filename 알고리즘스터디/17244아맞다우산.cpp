#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321


using namespace std;

struct State {
    int key;
    int cnt;
    State(int k = 0, int c = INF) : key(k), cnt(c) {}
};

struct Point {
    int y;
    int x;
    int key;
    int cnt;
    Point(int a = 0, int b = 0, int k = 0, int c = 0) : y(a), x(b) {}
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int N, M;
vector<vector<State>> map;


int getMinPath(int y, int x) {
    queue<Point> q;
    q.push(Point(y, x, 0, 0));

    map[y][x].cnt = 0;
    map[y][x].key = 0;
    
    
    while(!q.empty()) {
        int cury = q.front().y;
        int curx = q.front().x;
        int curKey = q.front().key;
        int curCnt = q.front().cnt;
        q.pop();

        map[cury][curx].cnt = curCnt;
        map[cury][curx].key = curKey;

        for(int dir = 0; dir < 4; dir++) {
            int nexty = cury + dy[dir];
            int nextx = curx + dx[dir];

            //벽
            if(map[nexty][nextx].cnt == INF) continue;
            if(map[nexty][nextx].key < map[cury][curx].key) continue;
            if(map[nexty][nextx].cnt < map[cury][curx].cnt)
            // X, .이면 가능
            


        }

    }
}


int main() {
    char input;
    int sy = 0;
    int sx = 0;

    cin >> N >> M;


    map.assign(N, vector<State>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> input;
            switch(input) {
                case '#':
                map[i][j].cnt = INF;
                break;
                case 'S':
                sy = i, sx = j;
                case '.':
                map[i][j].cnt = INF - 1;
                map[i][j].key = 0;
                break;
                case 'X':
                map[i][j].key = -1;
                break;
                case 'E':
                map[i][j].key = -2;
                break;
            }
        }
    }

    int minPath = getMinPath(sy, sx);


    
    return 0;
}