#include <iostream>
#include <vector>
#include <queue>

using namespace std;




void addEdge(vector<vector<int>>& adj_list, vector<int>& indegree, int u, int v) {
    adj_list[u].push_back(v);
    indegree[v]++;
}

vector<int> topologicalSort(const vector<vector<int>>& adj_list, vector<int>& indegree) { 
    int N = indegree.size() - 1;
    queue<int> q;
    vector<int> ret;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    for(int i = 0; i < N; i++) {
        if(q.empty()) {
            cout << "has Cycle\n";
            return ret;
        }
        int current = q.front();
        q.pop();
        ret.push_back(current);
        for(int j = 0; j < adj_list[current].size(); j++) {
            int next = adj_list[current][j];
            if(--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adj_list(N + 1, vector<int>());
    vector<int> indegree(N + 1, 0);
    vector<int> result;
    
    int studentA, studentB;
    for(int i = 0; i < M; i++) {
        cin >> studentA >> studentB;
        addEdge(adj_list, indegree, studentA, studentB);
    }

    result = topologicalSort(adj_list, indegree);

    for(const auto& element : result) {
        cout << element << ' ';
    }

    return 0;
}