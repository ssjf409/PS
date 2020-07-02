#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
vector<vector<pair<int, int>>> vertex;
vector<int> dist;
vector<int> parent;
vector<int> path;

int dijkstra(int start, int end) {
    // weight, vertex
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cdist = -pq.top().first;
        pq.pop();

        if(cur == end) {
            int temp = end;
            while(temp != start) {
                path.push_back(temp);
                temp = parent[temp];
            }
            path.push_back(temp);

            return cdist;
        }
        
        for(int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i].first;
            int nextDist = cdist + vertex[cur][i].second;
            if(nextDist < dist[next]) {
                parent[next] = cur;
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
}


int main() {
    cin >> n >> m;
    vertex.assign(n + 1, vector<pair<int, int>>());
    dist.assign(n + 1, INF);
    parent.assign(n + 1, 0);

    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        vertex[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    cout << dijkstra(start, end) << '\n';



    cout << path.size() << '\n';

    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }


    return 0;
}