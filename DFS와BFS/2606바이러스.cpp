#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int cnt;
vector<vector<int>> board;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < board[cur].size(); i++) {
            int next = board[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            cnt++;
            q.push(next);
        }
    }

}

int main() {
    cin >> N >> M;

    board.assign(N, vector<int>());
    visited.assign(N, false);

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        board[a - 1].push_back(b - 1);
        board[b - 1].push_back(a - 1);
    }


    bfs(0);
    cout << cnt;

    return 0;
}