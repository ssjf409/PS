#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int ,int>> vertex;
vector<bool> visited;

inline double getDist(int a, int b) {
    return sqrt(pow(vertex[a].first - vertex[b].first, 2) + pow(vertex[a].second - vertex[b].second, 2));
}

int main() {
    cin >> N >> M;

    vertex.assign(N + 1, pair<int, int>());
    visited.assign(N + 1, false);
    for(int i = 1; i <= N; i++) {
        cin >> vertex[i].first >> vertex[i].second;
    }

    if(N - 1 <= M) {
        int a, b;
        for(int j = 1; j <= M; j++) {
            cin >> a >> b;
        }
        cout << "0.00";
        return 0;
    }

    priority_queue<pair<double, int>> pq;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        for(int j = 1; j <= N; j++) {
            if(!visited[a] && j != a) {
                pq.push({-getDist(a, j), j});
            }
            if(!visited[b] && j != b) {
                pq.push({-getDist(b, j), j});
            }
        }
        visited[a] = true;
        visited[b] = true;
    }

    int cnt = 0;
    double sum = 0.0;
    for(int i = 1; i <= N; i++) {
        if(visited[i]) cnt++;
    }

    while(!pq.empty()) {
        double cdist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(visited[cur]) continue;
        visited[cur] = true;
        cnt++;
        sum += cdist;
        if(cnt == N) {
            cout << fixed;
            cout.precision(2);
            cout << sum;
            break;
        }

        for(int i = 1; i <= N; i++) {
            if(visited[i] || cur == i) continue;
            pq.push({-getDist(cur, i), i});
        }
    }


    return 0;
}