#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

int N, F, cnt = 0;
int parent[100000];
int friends[100000];

int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    
    if(a > b) {
        parent[a] = b;
        friends[b] += friends[a];
    }
    else {
        parent[b] = a;
        friends[a] += friends[b];
    }
}

int main() {
    cin >> N;

    for(int testCase = 0; testCase < N; testCase++) {
        cin >> F;
        cnt = 0;
        memset(parent, 0, sizeof(parent));
        memset(friends, 0, sizeof(friends));

        unordered_map<string, int> m;

        string a, b;
        for(int i = 0; i < F; i++) {
            cin >> a >> b;
            if(m.find(a) == m.end()) {
                parent[cnt] = cnt;
                friends[cnt] = 1;
                m.insert({a, cnt++});
            }
            if(m.find(b) == m.end()) {
                parent[cnt] = cnt;
                friends[cnt] = 1;
                m.insert({b, cnt++});
            }
            unionParent(m[a], m[b]);

            cout << friends[0] << '\n';
        }
    }

    return 0;
}