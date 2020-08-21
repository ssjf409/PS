#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector<vector<int>> adj;

vector<ll> sheep;

ll getSaveSheepNum(int here) {
    if(adj[here].size() == 0) return max(sheep[here], (ll)0);

    ll ret = sheep[here];

    for(int i = 0; i < adj[here].size(); i++) {
        ret += getSaveSheepNum(adj[here][i]);
    }

    return max(ret, (ll)0);
}

int main() {
    cin >> N;
    adj.assign(N + 1, vector<int>());
    sheep.assign(N + 1, 0);

    char cmd;
    ll num;
    int u;
    for(int i = 2; i <= N; i++) {
        cin >> cmd >> num >> u;
        if(cmd == 'S') sheep[i] = num;
        else sheep[i] = -num;
        adj[u].push_back(i);
    }

    cout << getSaveSheepNum(1);


    return 0;
}