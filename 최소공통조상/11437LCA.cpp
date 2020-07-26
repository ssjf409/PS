#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> adj;
vector<int> depth;
vector<bool> visited;
vector<int> parents;

void dfs(int here, int d) {
    depth[here] = d;

    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(visited[next]) continue;
        visited[next] = true;
        parents[next] = here;
        dfs(next, d + 1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    adj.assign(N + 1, vector<int>());
    depth.assign(N + 1, -1);
    visited.assign(N + 1, false);
    parents.assign(N + 1, 0);

    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = true;
    dfs(1, 0);

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        
        while(depth[u] != depth[v]) {
            if(depth[u] < depth[v]) v = parents[v];
            else u = parents[u];
        }
        while(u != v) {
            v = parents[v];
            u = parents[u];
        }
        cout << v << '\n';
    }



    return 0;
}