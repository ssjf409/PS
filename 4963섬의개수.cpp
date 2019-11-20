#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v_map;
vector<vector<bool>> v_visit;

int island_num = 0;

void bfs(pair<int, int> p) {
    queue<pair<int, int>> q;
    q.push(p);
    if(v_map[p.first][p.second] == 1 && v_visit[p.first][p.second] == false) {
        island_num++;
    }
    v_visit[p.first][p.second] = true;
    if(v_map[p.first][p.second] == 0) {
        return;
    }
    while(!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                pair<int, int> temp_around = make_pair(temp.first + i - 1, temp.second + j - 1);
                if(temp.first == temp_around.first && temp.second == temp_around.second){
                    continue;
                } else if(!v_visit[temp_around.first][temp_around.second] && v_map[temp_around.first][temp_around.second] == 1) {
                    q.push(temp_around);
                    v_visit[temp_around.first][temp_around.second] = true;
                }

            }
        }
    }
}

int main() {
    int w;
    int h;
    while(true) {
        cin >> w >> h;

        if(w == 0 && h == 0) {
            break;
        }

        v_map.clear();
        v_visit.clear();
        island_num = 0;

        v_map.assign(h+2, vector<int>(w+2, 0));
        v_visit.assign(h+2, vector<bool>(w+2, false));

        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                cin >> v_map[i][j];
            }
        }

        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                bfs(make_pair(i, j));
            }
        }

        cout << island_num << '\n';

        
        
    }
    return 0;
}