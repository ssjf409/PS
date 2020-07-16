#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> cache;
vector<bool> visited;

int N, R, Q;

int dfs(int node) {
    visited[node] = true;

    int& ret = cache[node];
    
    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(visited[next]) continue;
        ret += dfs(next);
    }

    return ++ret;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> R >> Q;

    adj.assign(N + 1, vector<int>());
    cache.assign(N + 1, 0);
    visited.assign(N + 1, false);

    
    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(R);

    
    int target;
    for(int i = 0; i < Q; i++) {
        cin >> target;
        cout << cache[target] << '\n';
    }

    return 0;
}