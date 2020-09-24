#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> cache;
vector<bool> isPrime;
int N, M;

int getNum(int cur) {

    int& ret = cache[cur];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i].first;
        ret += getNum(next) * adj[cur][i].second;
    }
    
    return (ret == 0 ? 1 : ret);

}

int main() {
    cin >> N >> M;


    adj.assign(N + 1, vector<pair<int, int>>());
    cache.assign(N + 1, -1);


    
    int u, v, n;
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> n;
        adj[u].push_back({v, n});
    }

    cout << getNum(N);


    return 0;
}