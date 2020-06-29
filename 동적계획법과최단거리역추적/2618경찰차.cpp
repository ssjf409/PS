#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, W;

int cache[1002][1002];
vector<pair<int, int>> point;
vector<pair<int, int>> point2;
vector<int> path;

inline int getDist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int getMinDistance(int pos1, int pos2) {
    if(pos1 >= W || pos2 >= W) return 0;

    int& ret = cache[pos1][pos2];
    if(ret != -1) return ret;

    int next = max(pos1, pos2) + 1;

    int a = getMinDistance(next, pos2) + getDist(point[pos1].first, point[pos1].second, point2[next].first, point2[next].second);
    int b = getMinDistance(pos1, next) + getDist(point[next].first, point[next].second, point2[pos2].first, point2[pos2].second);

    ret = min(a, b);

    return ret;
}



void reconstruct(int pos1, int pos2) {
    if(pos1 >= W || pos2 >= W) return;

    int next = max(pos1, pos2) + 1;
    int dist1 = cache[next][pos2] + getDist(point[pos1].first, point[pos1].second, point2[next].first, point2[next].second);
    int dist2 = cache[pos1][next] + getDist(point[next].first, point[next].second, point2[pos2].first, point2[pos2].second);

    if(dist1 > dist2) {
        path.push_back(2);
        reconstruct(pos1, next);
    } else {
        path.push_back(1);
        reconstruct(next, pos2);
    }
}






int main() {
    cin >> N >> W;

    point.assign(W + 1, pair<int, int>());
    point2.assign(W + 2, pair<int, int>());

    memset(cache, -1, sizeof(cache));

    point[0] = {1, 1};
    point2[0] = {N, N};

    for(int i = 1; i <= W; i++) {
        cin >> point[i].first >> point[i].second;
        point2[i] = point[i];
    }

    cout << getMinDistance(0, 0) << '\n';

    reconstruct(0, 0);

    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }

    return 0;
}