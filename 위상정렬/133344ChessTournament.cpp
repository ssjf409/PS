#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> parents;
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

bool topologicalSort(const vector<int>& gIndegree, const vector<set<int>>& gAdj) {
    queue<int> q;
    vector<bool> visited(gIndegree.size(), false);
    for(int i = 0; i < N; i++) {
        if(!gIndegree[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    for(int i = 0; i < N; i++) {
        if(q.empty()) {
            return false;
        }
        int cur = q.front();
        q.pop();

        for(const auto& next : gAdj[cur]) {
            if(visited[findParent(next)]) return false;
            if(--indegree[next] == 0) {
                visited[findParent(next)] = true;
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

    vector<int> gIndegree(N, 0);
    vector<set<int>> gAdj(N, set<int>());
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            gAdj[findParent(i)].insert(adj[i][j]);
        }
    }

    set<int>::iterator iter;

    for(int i = 0; i < N; i++) {
        if(gAdj[i].size() == 0) continue;

        for(iter = gAdj[i].begin(); iter != gAdj[i].end(); iter++) {
            gIndegree[*iter]++;
        }
    }

    // for(int i = 0; i < N; i++) {
    //     cout << gIndegree[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < N; i++) {
    //     for(iter = gAdj[i].begin(); iter != gAdj[i].end(); iter++) {
    //         cout << *iter << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    if(topologicalSort(gIndegree, gAdj)) {
        cout << "consistent";
    } else {
        cout << "inconsistent";
    };


    return 0;
}