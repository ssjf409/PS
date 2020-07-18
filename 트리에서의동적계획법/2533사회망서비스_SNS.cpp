#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<bool>> visited;
vector<vector<int>> cache;

int dfs(int cur, bool mustChoose) {
    if(visited[cur][mustChoose]) return 0;
    visited[cur][mustChoose] = true;

    int& ret = cache[cur][mustChoose];
    if(ret != -1) return ret;

    ret = 0;
    
    for(int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(mustChoose) {
            ret += dfs(next, false);
        } else {
            ret += min(dfs(next, true) + 1, dfs(next, false));
        }
        visited[next][mustChoose] = false;
    }
    
    return ret;
}

int main() {
    cin >> N;
    adj.assign(N + 1, vector<int>());
    visited.assign(N + 1, vector<bool>(2, false));
    cache.assign(N + 1, vector<int>(2, -1));

    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << min(dfs(1, false) + 1, dfs(1, true)) << '\n';
    
    for(int i = 0; i < cache.size(); i++) {
        cout << cache[i][0] << ' ';
    }
    cout << endl;
    
    for(int i = 0; i < cache.size(); i++) {
        cout << cache[i][1] << ' ';
    }

    return 0;
}