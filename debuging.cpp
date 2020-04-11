#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;


void addEdge(vector<vector<int>>& adj_list, vector<int>& indegree, int u, int v) {
    adj_list[u].push_back(v);
    indegree[v]++;
}

vector<int> topologicalSort(const vector<vector<int>>& adj_list, vector<int>& indegree, vector<int>& load) {
    int N = indegree.size() - 1;
    vector<int> sum(N + 1, 0);
    queue<int> q;
    // vector<int> ret;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    for(int i = 1; i <= N; i++) {
        if(q.empty()) {
            cout << "has cycle";
            return sum;
        }
        int current = q.front();
        q.pop();
        sum[current] += load[current];
        for(int j = 0; j < adj_list[current].size(); j++) {
            int next = adj_list[current][j];
            if(sum[next] < load[current]) {
                sum[next] = load[current];
            }
            if(--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    return sum;

}

int main() {
    
    

    int N, cnt, K;
    cin >> N;

    vector<vector<int>> adj_list(N + 1, vector<int>());
    vector<int> indegree(N + 1 , 0);
    vector<int> load(N + 1, 0);
    vector<int> result;


    for(int i = 1; i <= N; i++) {
        cin >> load[i] >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> K;
            addEdge(adj_list, indegree, K, i);
        }
    }
    
    result = topologicalSort(adj_list, indegree, load);

    for(const auto& element : result) {
        cout << element << ' ';
    }
    return 0;
}
