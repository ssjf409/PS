#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int caseNum;
vector<bool> visited;
// {v, w}
vector<vector<pair<int, int>>> adj;


pair<int, int> bfs(int start) {
    priority_queue<pair<int, int>> pq;
    // node, w
    pq.push({0, start});
    visited[start] = true;

    int time = 0;
    int num = 1;

    while(!pq.empty()) {
        int qSize = pq.size();
        for(int i = 0; i < qSize; i++) {

        }
    }

}

int main() {
    cin >> caseNum;
    int n, d, c;
    while(caseNum--) {
        cin >> n >> d >> c;
        int u, v, w;

        adj.assign(n + 1, vector<pair<int, int>>());
        visited.assign(n + 1, false);


        for(int i = 0; i < d; i++) {
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
        }
        pair<int, int> a = bfs(c);
        cout << a.first << ' ' << a.second << '\n';

    }

    return 0;
}