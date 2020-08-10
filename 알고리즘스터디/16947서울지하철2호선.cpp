#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, cycleNum;

vector<vector<int>> adj;
vector<bool> visiting;
vector<bool> visited;
vector<int> parent;

bool findCircle(int prev, int here) {
    if(visiting[here]) {
        cycleNum = here;
        return true;
    }
    if(visited[here]) return false;
    visited[here] = true;
    visiting[here] = true;

    for(int i = 0; i < adj[here].size(); i++) {
        if(prev == adj[here][i]) continue;
        parent[here] = adj[here][i];
        if(findCircle(here, adj[here][i])) return true;
    }

    visiting[here] = false;
    return false;
}


int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

int bfs(int cycleParent, int start) {
    if(visiting[start]) return 0;
    vector<bool> dfs_visited(N + 1, false);
    queue<int> q;
    q.push(start);
    dfs_visited[start] = true;

    int dist = 0;
    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();


            if(findParent(cur) == cycleParent) return dist;

            for(int j = 0; j < adj[cur].size(); j++) {
                int next = adj[cur][j];
                if(dfs_visited[next]) continue;
                dfs_visited[next] = true;
                q.push(next);
            }

        }
        dist++;
    }

    return -1;
}

int main() {
    cin >> N;

    adj.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);
    visiting.assign(N + 1, false);
    parent.resize(N + 1);


    int u, v;
    for(int i = 0; i < N; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findCircle(0, 1);

    int temp = 1;
    while(temp != cycleNum) {
        visiting[temp] = false;
        temp = parent[temp];
    }

    
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }




    for(int i = 1; i <= N; i++) {
        if(visiting[i]) {
            unionParent(cycleNum, i);
        }
    }

    int cycleParent = findParent(cycleNum);

    vector<int> dist;

    for(int i = 1; i <= N; i++) {
        int temp = bfs(cycleParent, i);
        dist.push_back(temp);
    }

    for(int i = 0; i < dist.size(); i++) {
        cout << dist[i] << ' ';
    }
    

    return 0;
}