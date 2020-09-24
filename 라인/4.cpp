#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 0, 1, 2, 3
// down, left, up, right
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<vector<bool>> visited;

int cnt = 0;
int N;

bool getDist(const vector<vector<int>>& maze, int y, int x, int dir) {
    if(y == N - 1 && x == N - 1) return true;
    
    for(int i = 3; i <= 6; i++) {
        int nextDir = (dir + i) % 4;
        int ny = y + dy[nextDir];
        int nx = x + dx[nextDir];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(maze[ny][nx] == 1) continue;
        cnt++;
        if(getDist(maze, ny, nx, nextDir)) return true;
        cnt++;
    }
    
    return false;
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    N = maze.size();
    
    getDist(maze, 0, 0, 0);
    
    answer = cnt;
    
    
    
    return answer;
}