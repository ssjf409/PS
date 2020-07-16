#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> weight;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> cache;

vector<int> ret;

int dfs(int cur, bool prev) {
    int& ret = cache[cur][prev];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(visited[next]) continue;
        visited[next] = true;
        ret += dfs(next, false);
        visited[next] = false;
    }

    int temp = 0;
    if(!prev) {
        temp = weight[cur];
        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            temp += dfs(next, true);
            visited[next] = false;
        }
    }
    ret = max(ret, temp);


    return ret;
}

void reconstruct(int start) {
    queue<pair<int, bool>> q;
    q.push({start, false});
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        bool prev = q.front().second;
        q.pop();

        bool flag = false;
        if(!prev && cache[cur][0] != cache[cur][1]) {
            flag = true;
            ret.push_back(cur);
        }

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, flag});
        }
    }
}



int main() {
    cin >> n;

    weight.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    cache.assign(n + 1, vector<int>(2, -1));

    for(int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    int u, v;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = true;
    cout << max(dfs(1, false), dfs(1, true)) << '\n';

    visited.assign(n + 1, false);
    reconstruct(1);

    sort(ret.begin(), ret.end());

    for(const auto& el : ret) {
        cout << el << ' ';
    }
    

    return 0;
}