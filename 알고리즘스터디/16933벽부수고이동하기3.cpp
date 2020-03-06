#include <iostream>
#include <vector>
#define INF 987654321
#include <queue>


using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct State {
    int y;
    int x;
    int K;
    int day;
};

bool inRange(vector<vector<int>>& map, int y, int x) {
    if(y < 0 || y == map.size()) return false;
    if(x < 0 || x == map[0].size()) return false;
    return true;
}

bool canGo(const vector<vector<int>>& map, vector<vector<int>>& visit, int y, int x) {
    if(map[y][x] > 1) {
        return false;
    }
    return true;
}

bool dfs(vector<vector<int>>& map, vector<vector<int>>& visit, State start) {
    queue<State> q;
    q.push(start);
    map[start.y][start.x] = start.day;
    bool flag = false;
    while(!q.empty()) {
        State state = q.front();
        q.pop();
        state.day++;
        if(state.y == map.size() - 1 && state.x == map[0].size() - 1) return true;
        if(map[state.y][state.x] <= state.day) continue;
        

        for(int direc = 0; direc < 4; direc++) {
            
        }

    }

    return false;

    
}


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> visit(N, vector<int>(M,0));

    int input;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            
        }
    }
    State state;
    state.day = 0; // day : odd, night : even
    state.K = K;
    state.y = 0;
    state.x = 0;
    if(dfs(map, visit, state)) {

    } else {
        cout << -1;
    }


    return 0;
}