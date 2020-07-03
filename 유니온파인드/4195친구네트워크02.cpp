#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <map>

using namespace std;

int N, F, cnt = 0;
int parent[200001];
int friends[200001];

int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

int unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a == b) {
        return friends[a];
    } else if(a > b) {
        parent[a] = b;
        friends[b] += friends[a];
        return friends[b];
    }
    else {
        parent[b] = a;
        friends[a] += friends[b];
        return friends[a];
    } 
}

int main() {    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    // scanf("%d", &N);
    cin >> N;

    for(int testCase = 0; testCase < N; testCase++) {
        // scanf("%d", &F);
        cin >> F;
        cnt = 0;
        memset(parent, 0, sizeof(parent));
        memset(friends, 0, sizeof(friends));

        //입력이 작아서 unordered_map이 더 유리하다.
        unordered_map<string, int> m;
        //map<string, int> m;

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

            // printf("%d\n",  unionParent(m[a], m[b]));
            cout << unionParent(m[a], m[b]) << '\n';
        }
    }

    return 0;
}