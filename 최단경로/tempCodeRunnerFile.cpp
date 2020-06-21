#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int T, N, M, K;

// distance, cost, location
vector<vector<pair<pair<int, int>, int>>> board;
//distance
vector<int> dist;

int dijkstra(int start) {
    // distance, cost, location
    priority_queue<pair<pair<int, int>, int>> pq;
    dist[start] = 0;
    pq.push({{0, 0}, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first.first;
        int curCost = -pq.top().first.second;
        pq.pop();

        if(dist[cur] < curDist) continue;
        if(curCost > M) continue;

        if(cur == N) return curDist;



        for(int i = 0; i < board[cur].size(); i++) {
            int next = board[cur][i].second;
            int nextDist = board[cur][i].first.first + curDist;
            int nextCost = board[cur][i].first.second + curCost;
            if(nextCost > M) continue;
            if(nextDist < dist[next]) { 
                dist[next] = nextDist;
                pq.push({{-nextDist, -nextCost}, next});
            }

        }

    }

    return -1;
}


int main() {
    cin >> T;
    for(int tCase = 0; tCase < T; tCase++) {
        cin >> N >> M >> K;
        
        // {pos, {cost, distance}}
        board.assign(N + 1, vector<pair<pair<int, int>, int>>());
        dist.assign(N + 1, INF);

        int u, v, c, d;
        for(int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            board[u].push_back({{d, c}, v});
        }

        int temp = dijkstra(1);
        if(temp == -1) {
            cout << "Poor KCM\n";
        } else {
            cout << temp << '\n';
        }
        

    }


    return 0;
}