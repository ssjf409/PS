#include <iostream>
#include <vector>

using namespace std;
int T, N;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

void dfs(int here, int d) {
    depth[here] = d;

    for(int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        dfs(next, d + 1);
    }
}


int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        adj.assign(N + 1, vector<int>());
        parent.assign(N + 1, 0);
        depth.assign(N + 1, 0);

        int u, v;
        for(int i = 0; i < N - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            parent[v] = u;
        }

        int root = 0;
        for(int i = 1; i <= N; i++) {
            if(!parent[i]) {
                root = i;
                break;
            }
        }

        dfs(root, 0);


        int a, b;
        cin >> a >> b;

        while(depth[a] != depth[b]) {
            if(depth[a] < depth[b]) {
                b = parent[b];
            } else {
                a = parent[a];
            }
        }
        while(a != b) {
            a = parent[a];
            b = parent[b];
        }
        cout << a << '\n';


    }


    return 0;
}