#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int connected = 1;

struct Point {
    int y;
    int x;
    Point(){}
    Point(int a, int b) : y(a), x(b) {
    }
};

vector<int> root;
vector<int> rank_;


/* find(x): 재귀 이용 */
int find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        // "경로 압축(Path Compression)"
        // find 하면서 만난 모든 값의 부모 노드를 root로 만든다.
        return root[x] = find(root[x]);
    }
}


/* union1(x, y): union-by-rank 최적화 */
bool union_(int x, int y){
    x = find(x);
    y = find(y);

    // 두 값의 root가 같으면(이미 같은 트리) 합치지 않는다.
    if(x == y)
        return false;

    // "union-by-rank 최적화"
    // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다. 즉, 높이가 더 높은 쪽을 root로 삼음
    if(rank_[x] < rank_[y]) {
        root[x] = y; // x의 root를 y로 변경
    } else {
        root[y] = x; // y의 root를 x로 변경
        if(rank_[x] == rank_[y])
        rank_[x]++; // 만약 높이가 같다면 합친 후 (x의 높이 + 1)
    }
    return true;
}

int canGo(const vector<vector<int>>& map, int y, int x, int curRoot) {
    if(y == 0 || x == 0 || y == map.size() || x == map.size()) return -1;
    else if(map[y][x] == -1) return 1;
    else if(map[y][x] == curRoot) return 2;
    else return 3;
}
int isMeet(const vector<vector<int>>& map, int y, int x, int curRoot) {
    for(int dir = 0; dir < 4; dir++) {
        if(y + dy[dir] == 0 || y + dy[dir] == map.size() || x + dx[dir] == 0 || x + dx[dir] == map.size()) continue;
        if(map[y + dy[dir]][x + dx[dir]] != curRoot) return dir;
    }
    return 0;
}

int getMinCnt(vector<vector<int>>& map, int K) {
    queue<Point> q;
    for(int i = 1; i < map.size(); i++) {
        for(int j = 1; j < map.size(); j++) {
            if(map[i][j] != -1) {
                q.push(Point(i, j));
            }
        }
    }
    int dayCnt = 0;
    while(true) {
        dayCnt++;
        int qSize = q.size();
        int curY, curX, curRoot, tempY, tempX;
        for(int i = 0; i < qSize; i++) {
            curY = q.front().y;
            curX = q.front().x;
            curRoot = map[curY][curX];
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                // cout << "==========\n";
                // cout << curY + dy[dir] << ' ' <<  curX + dx[dir] << '\n';
                switch(canGo(map, curY + dy[dir], curX + dx[dir], curRoot)) {
                    
                    // 범위 벗어남
                    // 자기 자신이랑 만남
                    case -1:
                    case 2:
                        // cout << "-1\n";
                        continue;
                        break;
                    // -1이라서 그냥 가도됨
                    case 1:
                        // cout << "111111111\n";
                        map[curY + dy[dir]][curX + dx[dir]] = curRoot;
                        q.push(Point(curY + dy[dir], curX + dx[dir]));
                        // 2칸 간격으로 되서 결국 마주치게 되는 것도 계산해야한다.
                        // tempY = curY + 2 * dy[dir];
                        // tempX = curX + 2 * dx[dir];
                        // // cout << "==================\n";
                        // // cout << tempY << ' ' << tempX << '\n';
                        // if(tempY != 0 && tempY != map.size() && tempX != 0 && tempX != map.size()) {
                        //     if(map[tempY][tempX] != -1 && map[curY][curX] != map[tempY][tempX]) {
                        //         int targetRoot = map[tempY][tempX];
                        //         if(union_(curRoot, targetRoot)) {
                        //             connected++;
                        //             if(connected == K) return dayCnt;
                        //         }
                        //     }
                        // }
                        break;
                    // 자기랑 다른 번호 만남
                    case 3:
                        // cout << "2222222222\n";
                        int targetRoot = map[curY + dy[dir]][curX + dx[dir]];
                        if(union_(curRoot, targetRoot)) {
                            connected++;
                            if(connected == K) return dayCnt;
                        }
                        break;
                }

            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> map(N + 1, vector<int>(N + 1, -1));

    root.assign(N, 0);
    rank_.assign(N, 0);
    for (int i = 0; i < K; i++) {
        root[i] = i;
    }

    int input, input2;
    for(int i = 0; i < K; i++) {
        cin >> input >> input2;
        map[input][input2] = i;
    }

    cout << getMinCnt(map, K);

    

    return 0;
}