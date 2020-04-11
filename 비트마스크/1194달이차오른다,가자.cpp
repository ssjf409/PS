#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};




int bfs(vector<vector<char>>& map, int y, int x) {
    int N = map.size();
    int M = map[0].size();

    int keyValue = 0;
    int cnt = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int step = q.size();
        cnt++;
        for(int i = 0; i < step; i++) {
            int cury = q.front().first;
            int curx = q.front().second;
            q.pop();
            map[cury][curx] = (char)keyValue + '2';

            for(int dir = 0; dir < 4; dir++) {
                int ty = cury + dy[dir];
                int tx = curx + dx[dir];
                if(ty < 0 || ty >= N || tx < 0 || tx >= M) continue;
                char section = map[ty][tx];
                if(section == '1') return cnt;
                if(section == '#') continue;
                if(section >= 'A' && section <= 'F') {
                    if(keyValue & (1 << (section - 'A'))) {
                        keyValue &= ~(1 << (section - 'A'));
                        q.push(make_pair(ty, tx));
                    }
                } else {
                    if(section >= 'a' && section <= 'f') {
                        keyValue |= (1 << (section - 'a'));
                    }
                    if((char)keyValue + '2' == section) continue;
                    q.push(make_pair(ty, tx));
                }
            }
        }
    }

    return cnt;
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M));

    int sY, sX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == '0') {
                sY = i;
                sX = j;
            }
        }
    }

    cout << bfs(map, sY, sX);

    return 0;
}