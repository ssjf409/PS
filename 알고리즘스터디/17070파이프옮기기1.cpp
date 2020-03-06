#include <iostream>
#include <vector>
#define RIGHT 1
#define DOWN 2
#define DIAGONAL 3

using namespace std;


int getPathCnt(const vector<vector<int>>& map, int y, int x, int before) {
    if(y == map.size() || x == map.size()) return 0;
    if(map[y][x]) return 0;
    if(before == DIAGONAL && (map[y-1][x] || map[y][x-1])) return 0;
    if(y == map.size() - 1 && x == map.size() - 1) return 1;

    int ret = 0;
    if(before == RIGHT) {
        ret = ret + getPathCnt(map, y, x + 1, RIGHT) + getPathCnt(map, y + 1, x + 1, DIAGONAL);
    }
    if(before == DOWN) {
        ret = ret + getPathCnt(map, y + 1, x, DOWN) + getPathCnt(map, y + 1, x + 1, DIAGONAL);
    }
    if(before == DIAGONAL) {
        ret = ret + getPathCnt(map, y, x + 1, RIGHT) + getPathCnt(map, y + 1, x, DOWN) + getPathCnt(map, y + 1, x + 1, DIAGONAL);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> map(N+1, vector<int>(N+1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    cout << getPathCnt(map, 1, 2, RIGHT);
    return 0;
}