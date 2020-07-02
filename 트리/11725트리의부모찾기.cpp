#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> vertex;
vector<bool> visited;
vector<int> parent;

void bfs(int start) {
    queue<int> q;
    parent[start] = 1;
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            parent[next] = cur;
            q.push(next);
        }
    }
}

int main() {
    cin >> N;
    vertex.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);
    parent.assign(N + 1, 0);

    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }

    bfs(1);

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}