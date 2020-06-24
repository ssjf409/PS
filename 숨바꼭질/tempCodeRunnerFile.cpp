#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;
int N, K;
vector<int> board;
vector<int> visited;
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

void bfs(int start) {   
    visitTime[start] = 0;
    queue<pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cur = q.front().first;
            int curTime = q.front().second;
            q.pop();

            
            if(cur == K) {
                return;
            }


            for(int dir = 0; dir < 3; dir++) {
                int next = move(cur, dir);
                if(next < 0 || next > 100001) continue;
                if(visitTime[next] < curTime + 1) continue;
                visited[next]++;
                visitTime[next] = curTime + 1;
                q.push({next, curTime + 1});
            }

        }
    }

    return;
}

int main() {
    cin >> N >> K;
    
    board.assign(100001, 0);
    visited.assign(100001, 0);
    visitTime.assign(100001, INF);

    bfs(N);
    cout << visitTime[K] << '\n';
    cout << visited[K];

    return 0;
}