#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> adj;
vector<int> parent;
vector<pair<int, int>> depth;

int nodeNum = 1;


void inorderTraverse(int here, int d) {
    if(depth.size() == d) depth.push_back({0, 0});
    if(adj[here].first == 0) return;

    if(adj[here].first != -1) {
        inorderTraverse(adj[here].first, d + 1);
    }

    if(depth[d].first == 0) {
        depth[d].first = depth[d].second = nodeNum;
    } else if(depth[d].first > nodeNum) {
        depth[d].first = nodeNum;
    } else if(depth[d].second < nodeNum) {
        depth[d].second = nodeNum;
    }


    nodeNum++;

    if(adj[here].second != -1) {

        inorderTraverse(adj[here].second, d + 1);
    }
}


int main() {
        
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    adj.assign(N + 1, {0, 0});
    parent.assign(N + 1, 0);

    int u, a, b;
    for(int i = 0; i < N; i++) {
        cin >> u >> a >> b;
        adj[u].first = a, adj[u].second = b;
        parent[a] = parent[b] = u;
    }

    int root;
    int temp = 1;
    while(parent[temp] != 0) {
        temp = parent[temp];
    }
    root = temp;

    parent.clear();
    
    vector<int>().swap(parent);
    // cout << parent.capacity() << endl;


    inorderTraverse(root, 0);

    // for(int i = 0; i < depth.size(); i++) {
    //     cout << i << ", " << depth[i].first << ' ' << depth[i].second << endl;
    // }

    int maxDepth = 0;
    int maxLen = 0;

    for(int i = 0; i < depth.size(); i++) {
        int curLen = depth[i].second - depth[i].first + 1;
        if(curLen > maxLen) {
            maxDepth = i + 1;
            maxLen = curLen;
        }
    }
    cout << maxDepth << ' ' << maxLen;

    return 0;
}