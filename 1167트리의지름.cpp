#include <iostream>
#include <vector>

using namespace std;

int V;
vector<vector<pair<int, int>>> vertex;
int path[100001];

int main() {
    cin >> V;

    vertex.assign(V + 1, vector<pair<int, int>>());

    int u, v, w;
    for(int i = 0; i < V; i++) {
        cin >> u;
        while(true) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            
            vertex[u].push_back({v, w});
            vertex[v].push_back({u, w});
        }
    }

    return 0;
}