#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<pair<double, double>> vertex;
vector<bool> visited;
int cnt = 0;

inline double getDist(int a, int b) {
    return sqrt((vertex[a].first - vertex[b].first) * (vertex[a].first - vertex[b].first) + 
            (vertex[a].second - vertex[b].second) * (vertex[a].second - vertex[b].second));
}

double getMST(int start) {
    // distance, vertex
    priority_queue<pair<double, int>> pq;
    pq.push({0.0, 0});

    double ret = 0.0;
    
    while(!pq.empty()) {
        double cdist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(visited[cur]) continue;
        visited[cur] = true;
        ret += cdist;
        cnt++;
        if(cnt == n) return ret; // n - 1개 고른다.

        for(int i = 0; i < n; i++) {
            if(cur == i) continue;
            pq.push({-getDist(cur, i), i});
        }
    }
}

int main() {
    cin >> n;
    vertex.assign(n, pair<double, double>());
    visited.assign(n, false);

    for(int i = 0; i < n; i++) {
        cin >> vertex[i].first >> vertex[i].second;
    }

    double sum = 0.0;

    cout << getMST(0);


    return 0;
}