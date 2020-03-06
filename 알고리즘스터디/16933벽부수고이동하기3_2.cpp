#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;


int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct State {
    int y;
    int x;
    int day;
    int K;
    State(int a, int b, int c, int d) : y(a), x(b), day(c), K(d) {}
};



bool isShortest(const vector<vector<int>>& map, const vector<vector<int>>& kmap, int y, int x, int day, int K) {
    if(map[y][x] == 1) return true;
    if(map[y][x] > day) return true;
    if(map[y][x] == day && kmap[y][x] < K) return true;
    return false;
}

bool inRange(const vector<vector<int>>& map, int y, int x) {
    if(y < 0 || y == map.size()) return false;
    if(x < 0 || x == map[0].size()) return false;
    return true;
}

int dfs(vector<vector<int>>& map, vector<vector<int>>& kmap, State& start) {
    queue<State> q;
    q.push(start);
    
    while(!q.empty()) {
        State tState = q.front();
        q.pop();
        if(!isShortest(map, kmap, tState.y , tState.x, tState.day, tState.K)) continue;
        map[tState.y][tState.x] = tState.day;
        kmap[tState.y][tState.x] = tState.K;
        
            // cout << '\n';
            // for(int i = 0; i < map.size(); i++) {
            //     for(int j = 0; j < map[0].size(); j++) {
            //         if(map[i][j] == INF) {
            //             cout << 0;
            //         } else {
            //             cout << map[i][j];
            //         }
            //     }
            //     cout << '\n';
            // }


        for(int direc = 0; direc < 4; direc++) {
            if(inRange(map, tState.y + dy[direc], tState.x + dx[direc]) && isShortest(map, kmap, tState.y + dy[direc], tState.x + dx[direc], tState.day, tState.K)) {
                if(map[tState.y + dy[direc]][tState.x + dx[direc]] != 1) {
                    q.push(State(tState.y + dy[direc], tState.x + dx[direc], tState.day + 1, tState.K));
                } else if(tState.K > 0) {
                    if(tState.day % 2 == 1) {
                        q.push(State(tState.y + dy[direc], tState.x + dx[direc], tState.day + 1, tState.K - 1));
                    } else {
                        q.push(State(tState.y + dy[direc], tState.x + dx[direc], tState.day + 2, tState.K - 1));
                    }
                }
            }
            
        }
        
    }
    return map[map.size() -1][map[0].size() - 1];
}


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> kmap(N, vector<int>(M, 0));
    
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            if(str[j] == '1') {
                map[i][j] = 1;
            } else {
                map[i][j] = INF;
            }
        }
    }

    State state(0, 0, 1, K);

    int result = dfs(map, kmap, state);

    if(result == INF) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}