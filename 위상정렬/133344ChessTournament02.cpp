#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> parents;
vector<int> visited;
int N, M;

int findParent(int a) {
    if(a == parents[a]) return a;
    return parents[a] = findParent(parents[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    
  
    if(a > b) {
        parents[a] = b;
    } else {
        parents[b] = a;
    }
}

bool topologicalSort() {
    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(!indegree[i]) {
            q.push(i);
        }
    }

    for(int i = 0; i < N; i++) {
        if(q.empty()) {
            return false;
        }
        int cur = q.front();
        q.pop();

        for(const auto next : adj[cur]) {
            if(--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return true;
}

int main() {
    cin >> N >> M;
    adj.assign(N, vector<int>());
    indegree.assign(N, 0);
    visited.assign(N, false);
    parents.assign(N, 0);

    for(int i = 0; i < parents.size(); i++) {
        parents[i] = i;
    }

    int verCnt = N;

    int a, b;
    char cmd;
    for(int i = 0; i < M; i++) {
        cin >> a >> cmd >> b;
        
        switch(cmd) {
            case '=':
                unionParent(a, b);
                break;
            case '>':
                adj[a].push_back(b);
                indegree[b]++;
                break;
            case '<':
                adj[b].push_back(a);
                indegree[a]++;
                break;
        }
    }

    if(topologicalSort()) {
        cout << "consistent";
    } else {
        cout << "inconsistent";
    };


    return 0;
}