#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int N, E;
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
        
        if(distance > dist[cur]) continue;

        for(int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i].second;
            int nextDist = distance + vertex[cur][i].first;
            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
}

int main() {
    cin >> N >> E;
    vertex.assign(N + 1, vector<pair<int, int>>());
    dist.assign(N + 1, INF);

    int u, v, w;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        vertex[u].push_back({w, v});
        vertex[v].push_back({w, u});
    }
    int firPoint, secPoint;
    cin >> firPoint >> secPoint;


    long long first = 0, second = 0;
    dijkstra(1);
    first = dist[firPoint];
    second = dist[secPoint];

    dist.assign(N + 1, INF);
    dijkstra(firPoint);
    first += dist[secPoint];
    second += dist[N];

    dist.assign(N + 1, INF);
    dijkstra(secPoint);
    first += dist[N];
    second += dist[firPoint];

    if(first >= INF) {
        if(second >= INF) {
            cout << -1;
        } else {
            cout << second;
        }
    } else {
        if(second >= INF) {
            cout << first;
        } else {
            cout << ((first > second) ? second : first);
        }
    }



    return 0;
}