#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& adjList, vector<int>& indegree, int u, int v) {
    adjList[u].push_back(v);
    indegree[v]++;
}

vector<int> topologicalSort(const vector<vector<int>>& adjList, vector<int>& indegree) {
    int N = indegree.size() - 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ret;

    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) pq.push(i);
    }

    for(int i = 0; i < N; i++) {
        if(pq.empty()) {
            cout << "has cycle";
            return ret;
        }
        int current = pq.top();
        pq.pop();
        ret.push_back(current);
        for(int j = 0; j < adjList[current].size(); j++) {
            int next = adjList[current][j];
            if(--indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N + 1, vector<int>());
    vector<int> indegree(N + 1, 0);
    vector<int> result;

    int input, input2;
    for(int i = 0; i < M; i++) {
        cin >> input >> input2;
        addEdge(adjList, indegree, input, input2);
    }

    result = topologicalSort(adjList, indegree);

    for(const auto& element : result) {
        cout << element << ' ';
    }

    return 0;
}