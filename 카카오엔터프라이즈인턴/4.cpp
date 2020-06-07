#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M;
vector<vector<int>> pos;
vector<bool> visited;




int shortestPath(int start, int end) {
    visited.assign(1 << N, false);

    // cost, position
    priority_queue<pair<int, int>> pq;
    
    visited[start] = true;
    pq.push({0, start});

    while(!pq.empty()) {
        int ccost = -pq.top().first;
        int cpos = pq.top().second;
        pq.pop();

        if(cpos == end) {
            return ccost;
        }

        visited[cpos] = true;

        
        for(int i = 0; i < (1 << N); i++) {
            if(visited[i]) continue;
            if(pos[cpos][i] == -1) continue;
            
            visited[i] = true;

            pq.push({-(ccost + pos[cpos][i]), i});
        }

    }

    return -1;
}

int main() {
    cin >> N >> M;
    pos.assign(1 << N, vector<int>(1 << N, -1));

    string str1, str2;
    int cost;
    for(int i = 0; i < M; i++) {
        cin >> str1 >> str2 >> cost;
        int p1 = 0;
        int p2 = 0;
        for(int j = 0; j < str1.size(); j++) {
            p1 = p1 << 1;
            p2 = p2 << 1;
            if(str1[j] == 'o') p1 += 1;
            if(str2[j] == 'o') p2 += 1;
        }

        
        pos[p1][p2] = cost;

    }

    
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> str1 >> str2;
        int p1 = 0;
        int p2 = 0;
        for(int j = 0; j < str1.size(); j++) {
            p1 = p1 << 1;
            p2 = p2 << 1;
            if(str1[j] == 'o') p1 += 1;
            if(str2[j] == 'o') p2 += 1;
        }

        cout << shortestPath(p1, p2) << '\n';

    }

    
	return 0;
}