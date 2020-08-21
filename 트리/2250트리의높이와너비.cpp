#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> adj;
vector<int> colNum;
vector<bool> visited;

int nodeNum = 1;

void inorderTraverse(int here) {
    if(adj[here].first != 0) {
        inorderTraverse(adj[here].first);
    }

    colNum[here] = nodeNum++;

    if(adj[here].second != 0) {
        inorderTraverse(adj[here].second);
    }
}

pair<int, int> getLongest(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    int depth = 0;
    int maxDepth = 0;
    int maxLength = 0;

    while(!q.empty()) {
        depth++;
        int qSize = q.size();
        int curMin = colNum[q.front()];
        int curMax = curMin;
        int curLen = 0;

        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();
            int curLoc = colNum[cur];
            if(curLoc < curMin) {
                curMin = curLoc;
            }
            if(curLoc > curMax) {
                curMax = curLoc;
            }

            if(adj[cur].first != -1 && !visited[adj[cur].first] ) {
                visited[adj[cur].first] = true;
                q.push(adj[cur].first);
            }
            
            if(adj[cur].second != -1 && !visited[adj[cur].second]) {
                visited[adj[cur].second] = true;
                q.push(adj[cur].second);
            }
        }

        curLen = curMax - curMin + 1;
        if(curLen > maxLength) {
            maxDepth = depth;
            maxLength = curLen;
        }
    }

    return {maxDepth, maxLength};
}


int main() {
    cin >> N;
    adj.assign(N + 1, {0, 0});
    colNum.assign(N + 1, -1);
    visited.assign(N + 1, false);
    
    int u, a, b;
    for(int i = 0; i < N; i++) {
        cin >> u >> a >> b;
        adj[u].first = a, adj[u].second = b;
        colNum[a] = colNum[b] = u;
    }

    int root;
    int temp = 1;
    while(colNum[temp] != -1) {
        temp = colNum[temp];
    }
    root = temp;

    colNum.assign(N + 1, 0);

    inorderTraverse(root);


    pair<int, int> result = getLongest(root);

    cout << result.first << ' ' << result.second;

    return 0;
}