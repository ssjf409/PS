#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& vertex, vector<int>& dist, int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    // weight, vertex
    pq.push({0, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cdist = -pq.top().first;
        pq.pop();


        if(cdist > dist[cur]) continue;


        for(int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i].second;
            int nextDist = cdist + vertex[cur][i].first;
            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
}


int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        vector<vector<pair<int, int>>> vertex(n + 1, vector<pair<int, int>>());
        vector<int> dist;

        int g_h;
        
        int a, b, d;
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> d;
            if((a == g && b == h) || (a == h && b == g)) g_h = d;
            vertex[a].push_back({d, b});
            vertex[b].push_back({d, a});
        }

        vector<int> result;
        int x;
        for(int j = 0; j < t; j++) {
            cin >> x;

            dist.assign(n + 1, INF);
            dijkstra(vertex, dist, s);
            int s_x = dist[x];
            int s_g = dist[g];
            int s_h = dist[h];

            dist.assign(n + 1, INF);
            dijkstra(vertex, dist, x);
            int g_x = dist[g];
            int h_x = dist[h];

            int pathA = s_g + g_h + h_x;
            int pathB = s_h + g_h + g_x;
            pathA = ((pathA > pathB) ? pathB : pathA);
            if(pathA == s_x) result.push_back(x);
        }
        sort(result.begin(), result.end());
        for(const auto& el : result) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}