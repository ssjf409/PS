#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

int N, K;
vector<bool> visited;
vector<int> parent;
vector<int> path;

inline int getNext(int pos, int dir) {
    switch(dir) {
        case 0:
            return pos + 1;
            break;
        case 1:
            return pos - 1;
            break;
        case 2:
            return pos * 2;
            break;
    }
    return -1;
}

int dfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    
    int cnt = 0;

    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();

            if(cur == K) {
                int temp = K;
                while(temp != N) {
                    path.push_back(temp);
                    temp = parent[temp];
                }
                path.push_back(N);
                return cnt;
            }
            
            for(int dir = 0; dir < 3; dir++) {
                int next = getNext(cur, dir);
                if(next < 0 || next > MAX) continue;
                if(visited[next]) continue;
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
        cnt++;
    }

    return -1;
}

int main() {
    cin >> N >> K;

    visited.assign(MAX + 1, false);
    parent.assign(MAX + 1, -1);

    cout << dfs(N) << '\n';

    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
    

    return 0;
}