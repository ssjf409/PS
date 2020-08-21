#include <iostream>
#include <vector>

using namespace std;

int N, deleteNode;
vector<vector<int>> adj;


int getLeafNode(int here) {
    if(adj[here].size() == 0) return 1;

    int ret = 0;
    
    for(int i = 0; i < adj[here].size(); i++) {
        ret += getLeafNode(adj[here][i]);
    }


    return ret;
}

int main() {
    cin >> N;
    adj.assign(N, vector<int>());

    vector<int> root;
    vector<int> input(N);
    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    cin >> deleteNode;

    int u;
    for(int i = 0; i < N; i++) {
        u = input[i];
        if(i == deleteNode) continue;
        if(u == -1) root.push_back(i);
        else {
            adj[u].push_back(i);
        }
    }


    int sum = 0;
    for(const auto el : root) {
        sum += getLeafNode(el);
    }
    cout << sum;

    return 0;
}