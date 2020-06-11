#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;
int V, E, K;
vector<vector<pair<int, int>>> vertex;
vector<int> dist;

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if(dist[cur] < distance) continue;

        for(int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i].first;
            int nextDist = distance + vertex[cur][i].second;

            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }

}


int main() {
    cin >> V >> E >> K;
    vertex.assign(V + 1, vector<pair<int, int>>());
    dist.assign(V + 1, INF);

    int u, v, w;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        vertex[u].push_back({v, w});
    }

    dijkstra(K);

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}