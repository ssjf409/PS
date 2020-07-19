#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<int> dist;
vector<int> indegree;

vector<vector<int>> adj;

int W;

int topologicalSort() {
    int n = adj.size();
    // position, total_cost
    queue<pair<int, int>> q;
    vector<int> cost(n, 0);

    for(int i = 1; i < n; i++) {
        cost[i] = dist[i];
        if(indegree[i] == 0) {
            q.push({i, dist[i]});
        }
    }

    for(int i = 1; i < n; i++) {
        if(q.empty()) {
            return -INF;
        }

        int cur = q.front().first;
        int ccost = q.front().second;
        q.pop();

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if(cost[next] < ccost + dist[next]) {
                cost[next] = ccost + dist[next];
            }
            if(--indegree[next] == 0) q.push({next, cost[next]});
        }

    }

    return cost[W];
}


int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    for(int testCase = 0; testCase < T; testCase++) {
        int N, K;
        cin >> N >> K;
        dist.assign(N + 1, INF);
        indegree.assign(N + 1, 0);
        adj.assign(N + 1, vector<int>());
        

        for(int i = 1; i <= N; i++) {
            cin >> dist[i];
        }

        int u, v;
        for(int i = 0; i < K; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
        }
        cin >> W;


        cout << topologicalSort() << '\n';
    }
    return 0;
}