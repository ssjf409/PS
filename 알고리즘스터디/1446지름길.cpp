#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N, D;
vector<int> dist;
vector<vector<pair<int ,int>>> shortPath;

int main() {
    cin >> N >> D;

    dist.assign(D + 1, INF);
    shortPath.assign(D + 1, vector<pair<int, int>>());

    int s, e, w;
    for(int i = 0; i < N; i++) {
        cin >> s >> e >> w;
        shortPath[s].push_back({e, w});
    }

    dist[0] = 0;

    for(int i = 0; i < D; i++) {
        int cdist = dist[i];
        if(dist[i + 1] > cdist + 1) {
            dist[i + 1] = cdist + 1;
        }
        for(int j = 0; j < shortPath[i].size(); j++) {
            int next = shortPath[i][j].first;
            int nextDist = shortPath[i][j].second + cdist;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
            }
        }
    }

    cout << dist[D];
    return 0;
}