#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<int> indegree;
vector<int> result;

// u -> v
// v++
void addEdge(int u, int v) {
    adj_list[u].push_back(v);
    indegree[v]++;
}

bool topologicalSort() {
    int n = adj_list.size() - 1;
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    for(int i = 0; i < n; i++) {
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
    
    return true;
}

int main() {
    
}