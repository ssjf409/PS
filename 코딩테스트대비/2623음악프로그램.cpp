#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<int> indegree;
vector<vector<int>> adj;
vector<int> result;
int N, M;

bool topologicalSort() {
    queue<int> q;
    for(int i = 1; i <= N; i++) {
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

    indegree.assign(N + 1, 0);
    adj.assign(N + 1, vector<int>());

    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        int prev, cur;
        cin >> prev;
        for(int j = 0; j < num - 1; j++) {
            cin >> cur;
            adj[prev].push_back(cur);
            indegree[cur]++;
            prev = cur;
        }
    }


    if(topologicalSort()) {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    } else {
        cout << 0;
    }

    return 0;
}