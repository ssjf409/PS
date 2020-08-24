#include <iostream>
#include <vector>

using namespace std;

int N, M, k;
vector<int> fee;
vector<int> parent;

int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(fee[a] <= fee[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}


int main() {
    cin >> N >> M >> k;

    fee.assign(N + 1, 0);
    parent.resize(N + 1);

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 1; i <= N; i++) {
        cin >> fee[i];
    }

    int u, v;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        unionParent(u, v);
    }

    int sum = 0;
    for(int i = 1; i <= N; i++) {
        int tempParent = findParent(i);
        if(tempParent != 0) {
            sum += fee[tempParent];
            unionParent(0, tempParent);
        }
    }

    if(sum <= k) {
        cout << sum;
    } else {
        cout << "Oh no";
    }



    return 0;
}