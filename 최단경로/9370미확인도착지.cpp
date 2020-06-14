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

    int ghPath = INF;

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
        vector<int> dist(n + 1, INF);
        vector<int> dist2(n + 1, INF);

        int g_h;
        
        int a, b, d;
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> d;
            if((a == g && b == h) || (a == h && b == g)) g_h = d;
            vertex[a].push_back({d, b});
            vertex[b].push_back({d, a});
        }

        vector<int> result;
        vector<int> target(t, 0);
        for(int j = 0; j < t; j++) {
            cin >> target[j];
        }


        int s_x;
        int mid1_mid2 = g_h;
        int mid1, mid2;
        

        dijkstra(vertex, dist, s);

        if(dist[g] > dist[h]) {
            mid1 = h;
            mid2 = g;
        } else {
            mid1 = g;
            mid2 = h;
        }

        dijkstra(vertex, dist2, mid2);

        for(int j = 0; j < target.size(); j++) {
            int path = dist[mid1] + mid1_mid2 + dist2[target[j]];
            if(path == dist[target[j]]) result.push_back(target[j]);
        }



        
        sort(result.begin(), result.end());
        for(const auto& el : result) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}