#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

struct Point {
    int y;
    int x;
    int root;
    Point() : y(0), x(0), root(0) {
    }
    Point(int i, int j, int r) : y(i), x(j), root(r) {
    }
};


int canGo(const vector<vector<int>>& map, int y, int x, int curRoot) {
    if(y == 0 || y == map.size() || x == 0 || x == map.size()) return 3;
    else if(map[y][x] == curRoot) return 3;
    else if(map[y][x] != -1) return 2;
    return 1;
}

// bool meetOther(const vector<vector<int>>& map, int y, int x, int direc) {
//     if(map[y + dy[direc]][x + dx[direc]] == -1 || (map[y + dy[direc]][x + dx[direc]] == map[y][x])) return false;
//     return true;
// }
int find(int root[], int x) {
    if (root[x] == x) {
        return x;
    } else {
        // "경로 압축(Path Compression)"
        // find 하면서 만난 모든 값의 부모 노드를 root로 만든다.
        return root[x] = find(root, root[x]);
    }
}
/* union1(x, y): union-by-rank 최적화 */
void union_(int root[], int rank[], int x, int y){
    x = find(root, x);
    y = find(root, y);

    // 두 값의 root가 같으면(이미 같은 트리) 합치지 않는다.
    if(x == y)
        return;

    // "union-by-rank 최적화"
    // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다. 즉, 높이가 더 높은 쪽을 root로 삼음
    if(rank[x] < rank[y]) {
        root[x] = y; // x의 root를 y로 변경
    } else {
        root[y] = x; // y의 root를 x로 변경
        if(rank[x] == rank[y])
        rank[x]++; // 만약 높이가 같다면 합친 후 (x의 높이 + 1)
    }
}


int getMinCnt(vector<vector<int>>& map, int K) {
    queue<Point> q;

    int rootCnt = 1;
    for(int i = 1; i < map.size(); i++) {
        for(int j = 1; j < map[0].size(); j++) {
            if(map[i][j] != -1) q.push(Point(i, j, rootCnt++));
        }
    }

    // make_set tree
    int root[K + 1] = {0,};
    int rank[K + 1] = {0,};
    for(int i = 1; i <= K; i++) {
        root[i] = i;
        rank[i] = 0;
    }
    
    int nationCnt = 1;
    int dayCnt = 0;
    while(nationCnt != K) {
        dayCnt++;
        int qCnt = q.size();
        int curY;
        int curX;
        int curRoot;
        for(int i = 0; i < qCnt; i++) {
            curY = q.front().y;
            curX = q.front().x;
            curRoot = q.front().root;
            q.pop();
            for(int d = 0; d < 4; d++) {
                switch(canGo(map, curY + dy[d], curX + dx[d], curRoot)) {
                    // 지도 밖 or 자기 자신 영토 만남
                    case 3:
                        continue;
                        break;
                    // -1인 지역 만남
                    case 1:
                        q.push(Point(curY + dy[d], curX + dx[d], curRoot));
                        map[curY + dy[d]][curX + dx[d]] = curRoot;
                        break;
                    // 다른 문명 만남
                    case 2:
                        cout << "=========\n";
                        int realRoot = find(root, map[curY + dy[d]][curX + dx[d]]);
                        if(realRoot != curRoot) {
                            union_(root, rank, curRoot, realRoot);
                            nationCnt++;
                        }
                        break;
                }
            }


        }
    }

    return dayCnt;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> map(N + 1, vector<int>(N + 1, -1));

    int input, input2;
    for(int i = 1; i <= K; i++) {
        cin >> input >> input2;
        map[input][input2] = i;
    }

    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int result = getMinCnt(map, K);

    

    return 0;
}