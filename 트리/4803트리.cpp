#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> visiting;


bool hasCycle(int prev, int here) {
    if(visiting[here]) return true;
    if(visited[here]) return false;
    visited[here] = true;
    visiting[here] = true;
    for(int i = 0; i < adj[here].size(); i++) {
        if(adj[here][i] == prev) continue;
        if(hasCycle(here, adj[here][i])) return true;
    }
    visiting[here] = false;
    return false;
}

int main() {
    int testCase = 0;
    while(true) {
        testCase++;
        int treeNum = 0;

        cin >> N >> M;
        if(N == 0 && M == 0) break;
        adj.assign(N + 1, vector<int>());
        visited.assign(N + 1, false);
        visiting.assign(N + 1, false);

        int u, v;
        for(int i = 0; i < M; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        for(int i = 1; i <= N; i++) {
            if(!visited[i] && !hasCycle(0, i)) {
                treeNum++;
            }
        }

        cout << "Case " << testCase << ": ";
        if(treeNum > 1) {
            cout << "A forest of " << treeNum << " trees.\n";
        } else if(treeNum == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "No trees.\n";
        }

    }

    return 0;
}