#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
bool visited[100001];

inline int oper(int n, int dir) {
    switch (dir) {
        case 0:
            return n - 1;
        case 1:
            return n + 1;
        case 2:
            return n * 2;
        default:
            return -1;
    }
}

int bfs(int N) {
    queue<int> q;
    visited[N] = true;
    q.push(N);
    int ret = 0;
    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();
            if(cur == K) return ret;

            for(int dir = 0; dir < 3; dir++) {
                int next = oper(cur, dir);
                if(next < 0 || next > 100000) continue;
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
        ret++;
    }
    return -1;
}

int main() {
    cin >> N >> K;

    memset(visited, false, sizeof(visited));

    cout << bfs(N);

    return 0;
}