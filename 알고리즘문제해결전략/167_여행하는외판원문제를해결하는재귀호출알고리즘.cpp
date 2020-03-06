#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

#define MAX 9

int n;
int dist[MAX][MAX];

int getShortestPath(vector<int>& path, vector<bool>& visited, int currentLength) {
    if(path.size() == n) {
        return currentLength + dist[0][path.back()];
    }
    int ret = INF;
    for(int next = 0; next < n; next++) {
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        int cand = getShortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}


int main() {
    return 0;
}