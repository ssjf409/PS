#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;

vector<string> adj;

vector<vector<vector<int>>> cache;

int getMaxOwner(int cur, int price, int visited) {
    
    int& ret = cache[cur][price][visited];
    if(ret != -1) return ret;

    visited |= (1 << cur);
    ret = 0;

    for(int i = 0; i < adj.size(); i++) {
        if(cur != i && adj[cur][i] - '0' >= price && ((visited & (1 << i)) == 0)) {
            ret = max(ret, getMaxOwner(i, adj[cur][i] - '0', visited));
        }
    }

    visited ^= (1 << cur);
    ret++;

    return ret;

}

int main() {

    cin >> N;

    cache.assign(N, vector<vector<int>>(10, vector<int>((1 << 15) + 1, -1)));

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        adj.push_back(str);
    }

    cout << getMaxOwner(0, 0, 0);


    return 0;
}