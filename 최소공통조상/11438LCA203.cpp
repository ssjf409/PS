#include <iostream>
#include <vector>
#define MAX 18

using namespace std;

int N, M;

vector<vector<int>> adj;
vector<int> depth;
vector<bool> visited;
vector<vector<int>> parents;

void dfs(int here, int d) {
    depth[here] = d;

    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(visited[next]) continue;
        visited[next] = true;
        parents[next][0] = here;
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
    parents.assign(N + 1, vector<int>(MAX, 0));

    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = true;
    dfs(1, 0);

    for(int j = 0; j < MAX - 1; j++) {
        for(int i = 2; i <= N; i++) {
            int k = parents[i][j];
            if(k != 0) parents[i][j + 1] = parents[k][j];
        }
    }


    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int j = 0; diff; j++) {
            if(diff % 2) u = parents[u][j];
            diff /= 2;
        }

        if(u != v){
            for(int j=MAX-1; j>=0; j--){
                if(parents[u][j] != 0 && parents[u][j] != parents[v][j]){
                    u = parents[u][j];
                    v = parents[v][j];
                }
            }
            u = parents[u][0];
        }

        cout << u  << '\n';
    }



    return 0;
}