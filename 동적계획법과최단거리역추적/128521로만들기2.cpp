#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N;
vector<bool> visited;
vector<int> parent;
int path[100];

inline int getNext(int cur, int dir) {
    switch(dir) {
        case 0:
            if(cur % 3 == 0) return cur / 3;
            break;
        case 1:
            if(cur % 2 == 0) return cur / 2;
            break;
        case 2:
            return cur - 1;
            break;
    }
    return -INF;
}

vector<int> getShortest(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);

    vector<int> ret;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == 1) {
            int before = cur;
            while(before != N) {
                ret.push_back(before);
                before = parent[before];
            }
            ret.push_back(before);

            return ret;
        }


        for(int dir = 0; dir < 3; dir++) {
            int next = getNext(cur, dir);
            if(next <= 0 || next > N) continue;
            if(visited[next]) continue;
            visited[next] = true;
            parent[next] = cur;
            q.push(next);
        }
        
    }

    return ret;
}


int main() {
    cin >> N;
    visited.assign(N + 1, false);
    parent.assign(N + 1, -1);

    vector<int> ret = getShortest(N);
    cout << ret.size() - 1 << '\n';

    for(int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }

    return 0;
}