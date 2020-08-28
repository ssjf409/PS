#include <iostream>
#include <vector>

using namespace std;

int N, M, Q;

vector<int> parent;
vector<pair<int, int>> conn;

int main() {
    parent.resize(N + 1);
    conn.resize(M + 1, pair<int, int>());

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    return 0;
}