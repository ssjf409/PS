#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;
int N, K;
vector<int> board;
vector<bool> visited;
vector<int> visitTime;

inline int move(int pos, int command) {
    switch(command) {
        case 0:
            return pos - 1;
            break;
        case 1:
            return pos + 1;
            break;
        case 2:
            return pos * 2;
            break;
    }
    return -INF;
}

int bfs(int start) {
    visitTime[start] = 0;
    visited[start] = true;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curTime = -pq.top().first;
        pq.pop();

        if(cur == K) {
            return visitTime[K];
        }

        for(int dir = 0; dir < 3; dir++) {
            int next = move(cur, dir);
            int nextTime = (dir == 2) ? curTime : curTime + 1;
            if(next < 0 || next >= 100001) continue;
            if(visitTime[next] <= nextTime) continue;
            visitTime[next] = nextTime;
            pq.push({-nextTime, next});
        }

    }
    return -1;
}

int main() {
    cin >> N >> K;
    
    board.assign(100001, 0);
    visited.assign(100001, false);
    visitTime.assign(100001, INF);

    cout << bfs(N);

    return 0;
}