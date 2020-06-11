#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

bool dijkstra(vector<vector<pair<int, int>>>& vertex, vector<int>& dist, int start, int end, int g_, int h_) {
    dist[start] = 0;
    priority_queue<pair<int, pair<int, bool>>> pq;
    // weight, vertex
    pq.push({0, {start, false}});


    int g = min(g_, h_);
    int h = max(g_, h_);
    int ghPath = INF;

    while(!pq.empty()) {
        int cur = pq.top().second.first;
        int cdist = -pq.top().first;
        int ghVisited = pq.top().second.second;
        pq.pop();


        if(ghVisited && (cur == end) && (ghPath > cdist)) ghPath = cdist;
        if(cdist > dist[cur]) continue;
        


        for(int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i].second;
            int nextDist = cdist + vertex[cur][i].first;
            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                if(g == min(next, cur) && h == max(next, cur)) {
                    pq.push({-nextDist, {next, true}});
                } else {
                    pq.push({-nextDist, {next, ghVisited}});
                }
            }
        }
    }

    return ghPath == dist[end];
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
            vertex[a].push_back({d, b});
            vertex[b].push_back({d, a});
        }

        vector<int> result;
        int x;
        for(int j = 0; j < t; j++) {
            cin >> x;

            dist.assign(n + 1, INF);
            if(dijkstra(vertex, dist, s, x, g, h)) result.push_back(x);
        }
        sort(result.begin(), result.end());
        for(const auto& el : result) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}