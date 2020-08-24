#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, K;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<int> parent;
int cnt = 0;

int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

bool unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a == b) return false;
    else if(a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
    return true;
}

vector<pair<int, int>> findSomethingStrange(int y, int x) {
    vector<pair<int, int>> ret;
    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(board[ny][nx] != 0 && findParent(board[y][x]) != findParent(board[ny][nx])) {
            ret.push_back({ny, nx});
        } else {
            ret.push_back({-1, -1});
        }
    }

    return ret;
}

int bfs(const vector<pair<int, int>>& start) {
    queue<pair<int, int>> q;

    for(int i = 0; i < start.size(); i++) {
        q.push({start[i].first, start[i].second});
        visited[start[i].first][start[i].second] = true;
    }

    int year = 0;

    while(!q.empty()) {
        int qSize = q.size();

        vector<pair<pair<int, int>, int>> newLand;


        // cout << endl;
        // cout << "=============\n";
        // for(int i = 0; i < N; i++) { 
        //     for(int j = 0; j < N; j++) {
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i < qSize; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();



            vector<pair<int, int>> temp = findSomethingStrange(cy, cx);

            for(int j = 0; j < temp.size(); j++) {
                if(temp[j].first != -1 && unionParent(board[cy][cx], board[temp[j].first][temp[j].second])) {
                    cnt++;
                }
            }
            if(cnt == K - 1) return year;

            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if(visited[ny][nx]) continue;
                visited[ny][nx] = true;
                newLand.push_back({{ny, nx}, findParent(board[cy][cx])});
                q.push({ny, nx});
            }
        }

        for(int i = 0; i < newLand.size(); i++) {
            int newy = newLand[i].first.first;
            int newx = newLand[i].first.second;
            int owner = newLand[i].second;
            board[newy][newx] = owner;
        }
        year++;
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    board.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));
    parent.resize(K + 1);

    vector<pair<int, int>> start;

    int a, b;
    for(int i = 1; i <= K; i++) {
        cin >> a >> b;
        board[a - 1][b - 1] = i;
        parent[i] = i;
        start.push_back({a - 1, b - 1});
    }

    cout << bfs(start);



    return 0;
}
