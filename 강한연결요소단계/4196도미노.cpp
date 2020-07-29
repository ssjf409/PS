#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int T, N, M;
vector<vector<int>> adj, revAdj;
vector<bool> visited;
stack<int> st;
vector<int> curSCC;

vector<vector<int>> SCC;

void dfs(int here) {
    if(visited[here]) return;
    visited[here] = true;

    st.push(here);

    for(int i = 0; i < adj[here].size(); i++) {
        dfs(adj[here][i]);
    }
}

void makeSCC(int here) {
    if(visited[here]) return;
    visited[here] = true;

    curSCC.push_back(here);

    for(int i = 0; i < revAdj[here].size(); i++ ) {
        makeSCC(revAdj[here][i]);
    }

}

int main() {
    cin >> T;

    int x, y;
    while(T--) {
        cin >> N >> M;

        adj.assign(N + 1, vector<int>());
        revAdj.assign(N + 1, vector<int>());
        visited.assign(N + 1, false);

        for(int i = 0; i < M; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            revAdj[y].push_back(x);
        }

        for(int i = 1; i <= N; i++) {
            dfs(i);
        }

        visited.assign(N + 1, false);

        while(!st.empty()) {
            int cur = st.top();
            st.pop();
            makeSCC(cur);
            if(!curSCC.empty()) {
                SCC.push_back(curSCC);
            }
            curSCC.clear();
        }
        cout << SCC.size();
        SCC.clear();
        
    }

    return 0;
}