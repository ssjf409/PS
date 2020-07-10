#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 987654321

using namespace std;
int N;
vector<pair<int, pair<int, int>>> adj;
vector<int> dist;
vector<bool> visited;

inline long long getDist(int a, int b) {
    return min(min(abs((long long)adj[a].first - adj[b].first), abs((long long)adj[a].second.first - adj[b].second.first)), abs((long long)adj[a].second.second - adj[b].second.second));
}

long long prim(int start) {
    dist[start] = 0;
    // dist, target
    priority_queue<pair<long long, int>> pq;
    pq.push({0, start});

    int cnt = 0;
    long long ret = 0;

    while(!pq.empty()) {
        long long cdist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(visited[cur]) continue;
        visited[cur] = true;
        cnt++;
        ret += cdist;
        if(cnt == N) return ret;

        for(int i = 0; i < N; i++) {
            if(visited[i] || cur == i) continue;
            long long nextDist = getDist(cur, i);
            if(nextDist >= dist[i]) continue;
            dist[i] = nextDist;
            pq.push({-nextDist, i});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    adj.assign(N, pair<int, pair<int, int>>());
    dist.assign(N, INF);
    visited.assign(N, false);

    int a, b, c;
    for(int i = 0; i < N; i++) {
        cin >> adj[i].first >> adj[i].second.first >> adj[i].second.second;
    }

    cout << prim(0);

    return 0;
}