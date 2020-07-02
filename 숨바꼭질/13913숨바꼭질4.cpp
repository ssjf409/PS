// 이 코드 틀림
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 100000
#define INF 987654321

using namespace std;

int N, K;
int previous[MAX + 1];
bool visited[MAX + 1];

inline int move(int cur, int dir) {
    switch(dir) {
        case 0:
            return cur - 1;
            break;
        case 1:
            return cur + 1;
            break;
        case 2:
            return cur * 2;
            break;
    }
    return -INF;
}

vector<int> bfs(int start) {
    // pos, time
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int curTime = q.front().second;
        q.pop();

        if(cur == K) {
            vector<int> ret;
            int idx = cur;
            while(idx != N) {
                ret.push_back(idx);
                idx = previous[idx];
            }
            ret.push_back(idx);

            return ret;
        }

        for(int dir = 0; dir < 3; dir++) {
            int next = move(cur, dir);
            if(next < 0 || next > MAX) continue;
            if(visited[next]) continue;
            visited[next] = true;
            previous[next] = cur;
            q.push({next, curTime + 1});
        }
    }
}



int main() {
    cin >> N >> K;

    vector<int> ret = bfs(N);
    
    cout << ret.size() << '\n';
    for(int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }
    

    return 0;
}