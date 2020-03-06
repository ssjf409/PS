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

bool isShortest(const vector<vector<int>>& map, const vector<vector<int>>& kmap, State state) {
    if(map[state.y][state.x] == 1) return true;
    // if(kmap[state.y][state.x] < state.K) return true;
    if(map[state.y][state.x] > state.day) return true;
    if(map[state.y][state.x] == state.day && kmap[state.y][state.x] < state.K) return true;
    return false;
}

bool inRange(const vector<vector<int>>& map, int y, int x) {
    if(y < 0 || y == map.size()) return false;
    if(x < 0 || x == map[0].size()) return false;
    return true;
}

int bfs(vector<vector<int>>& map, vector<vector<int>>& kmap, State start) {
    queue<State> q;
    q.push(start);

    while(!q.empty()) {
        State state = q.front();
        q.pop();

        //
        if(!isShortest(map, kmap, state)) continue;
        int y = state.y;
        int x = state.x;
        int day = state.day;
        int k = state.K;
        if(map[y][x] != 1) {
            map[y][x] = day;
        }
        kmap[y][x] = k;


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




        for(int dir = 0; dir < 4; dir++) {
            if(inRange(map, y + dy[dir], x + dx[dir])) {
                if(map[y + dy[dir]][x + dx[dir]] != 1) {
                    q.push(State(y + dy[dir], x + dx[dir], day + 1, k));
                } else if(k > 0) {
                    if(day % 2 == 1) {
                        q.push(State(y + dy[dir], x + dx[dir], day + 1, k - 1));
                    } else {
                        q.push(State(y + dy[dir], x + dx[dir], day + 2, k - 1));
                    }
                }
            }
        }

    }


    return map[map.size() - 1][map[0].size() - 1];
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> kmap(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        for(int j = 0; j < M; j++) {
            if(str[j] == '1') {
                map[i][j] = 1;
            } else {
                map[i][j] = INF;
            }
        }
    }

    // State state(0, 0, 1, K);

    int result;
    for(int i = 1; i <= K; i++) {
        result = bfs(map, kmap, State(0, 0, 1, i));
    }
    if(result == INF) {
        cout << -1;
    } else {
        cout << result;
    }
    return 0;
}