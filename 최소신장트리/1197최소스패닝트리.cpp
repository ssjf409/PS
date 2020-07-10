#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> adj;
vector<int> parents;
int V, E;

int findParent(int a) {
    if(a == parents[a]) return a;
    return parents[a] = findParent(parents[a]);
}

bool unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a == b) return false;
    else if(a > b) parents[a] = b;
    else parents[b] = a;
    return true;
}

int main() {
    cin >> V >> E;
    parents.assign(V + 1, 0);
    for(int i = 0; i <= V; i++) {
        parents[i] = i;
    }

    int a, b ,c;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        // weight, u, v;
        adj.push_back({c, {a, b}});
    }

    sort(adj.begin(), adj.end());

    int cnt = 0;
    int sum = 0;
    for(int i = 0; cnt < V - 1 && i < adj.size(); i++) {
        if(unionParent(adj[i].second.first, adj[i].second.second)) {
            cnt++;
            sum += adj[i].first;
        }
    }

    cout << sum;

    return 0;
}