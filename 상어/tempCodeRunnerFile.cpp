#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int fishCnt[7];
int N;
vector<vector<int>> board;
vector<vector<bool>> visited;

inline int countEdible(int size) {
    int cnt = 0;
    int min = size < 7 ? size : 7;
    for(int i = 1; i < min; i++) {
        cnt += fishCnt[i];
    }
    return cnt;
}

int BFS(int y, int x) {
    // eatCount, cury, curx
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {y, x}});
    visited[y][x] = true;
    int step = 0;
    int size = 2;
    int ret = 0;

    priority_queue<pair<pair<int, int>, int>> pq;


    while(!q.empty()) {
        int qSize = q.size();
        bool flag = false;
        for(int i = 0; i < qSize; i++) {
            int ceat = q.front().first;
            int cy = q.front().second.first;
            int cx = q.front().second.second;
            q.pop();

            if(countEdible(size) == 0) return step;

            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if(board[ny][nx] > size) continue;
                if(visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if(board[ny][nx] >= 1 && board[ny][nx] < size) {
                    flag = true;
                    pq.push({{-ny, -nx}, ceat + 1});
                }
                q.push({ceat, {ny, nx}});
            }
        }

        if(flag) {
            while(!q.empty()) {
                q.pop();
            }

            


            int ny = -pq.top().first.first;
            int nx = -pq.top().first.second;
            int ceat = pq.top().second % size; 
            q.push({ceat, {ny, nx}});
            size += pq.top().second / size;
            ret = size;
            fishCnt[board[ny][nx]]--;
            board[ny][nx] = 0;
            visited.assign(N, vector<bool>(N, false));
            visited[ny][nx] = true;
            

                    cout << '\n';
                    cout << countEdible(size) << endl;
                    cout << "step : " << step + 1 << endl;
                    cout << "size : " << size << endl;
                    cout << "eat  : " << ceat << endl;
                    for(int i = 1; i <= 6; i++) {
                        cout << fishCnt[i] << ' ';
                    }
                    cout << endl;

            
                    for(int i = 0; i < N; i++) {
                        for(int j = 0; j < N; j++) {
                            cout << board[i][j] << ' ';
                        }
                        cout << '\n';
                    }
                    cout << '\n';

            while(!pq.empty()) {
                pq.pop();
            }
        }

        step++;
    }
    return ret;
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));
    int starty, startx;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 6) fishCnt[board[i][j]]++;
            else if(board[i][j] == 9) {
                board[i][j] = 0;
                starty = i;
                startx = j;
            }
        }
    }

    cout << BFS(starty, startx);

    return 0;
}