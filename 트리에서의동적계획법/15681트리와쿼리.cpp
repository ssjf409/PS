#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    // int numChildren = 0;
    vector<Node*> children;
};

vector<int> numChildren;

vector<vector<int>> adj;
vector<bool> visited;

Node* root;

int N, R, Q;

Node* dfs(int cur) {
    Node* ret = new Node();
    ret->data = cur;
    visited[cur] = true;

    for(int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(visited[next]) continue;
        ret->children.push_back(dfs(adj[cur][i]));
    }

    for(int i = 0; i < ret->children.size(); i++) {
        numChildren[cur] += numChildren[ret->children[i]->data] + 1;
    }

    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> R >> Q;
    adj.assign(N + 1, vector<int>());
    numChildren.assign(N + 1, 0);
    visited.assign(N + 1, false);

    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int target;
    root = dfs(R);

    for(int i = 0; i < Q; i++) {
        cin >> target;
        cout << numChildren[target] + 1 << '\n';
    }


    return 0;
}