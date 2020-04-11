#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<int> indegree;
queue<int> q;
vector<int> result;

void addEdge(int u, int v) {
    adj_list[u].push_back(v);
    indegree[v]++;
}

bool topologicalSort(int N) {
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    

    for(int i = 0; i < N; i++) {
        if(q.empty()) {
            return false;
        }   
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        
        for(int j = 0; j < adj_list[cur].size(); j++) {
            int a = adj_list[cur][j];
            if(--indegree[a] == 0) q.push(a);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    indegree.assign(N + 1, 0);
    adj_list.assign(N + 1,vector<int>());

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        addEdge(a, b);
    }


    topologicalSort(N + 1);
    
    for(int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
    }

    

    return 0;
}