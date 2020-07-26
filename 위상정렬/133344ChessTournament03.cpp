#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> parents;
vector<int> visited;
vector<int> visiting;
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

bool findCircle(int here) {
    here = findParent(here);
    if(visiting[here]) return true;
    if(visited[here]) return false;
    visiting[here] = true;
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); i++) {
        if(findCircle(adj[here][i])) return true;
    }
    visiting[here] = false;
    return false;
}

int main() {
    cin >> N >> M;
    adj.assign(N, vector<int>());
    indegree.assign(N, 0);
    visited.assign(N, false);
    visiting.assign(N, false);
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
                break;
            case '<':
                adj[b].push_back(a);
                break;
        }
    }

    bool flag = false;
    for(int i = 0; i < N; i++) {
        if(findCircle(i)) {
            flag = true;
            break;
        }
    }

    if(flag) {
        cout << "consistent";
    } else {
        cout << "inconsistent";
    };


    return 0;
}