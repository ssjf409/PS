#include <iostream>
#include <cstdio>

using namespace std;

int parent[1000001];

int findParent(int a) {
    if(parent[a] == a) return a;

    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}


int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int com, a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &com, &a, &b);
        if(com) {
            if(findParent(a) == findParent(b)) printf("YES\n");
            else printf("NO\n");
        } else {
            unionParent(a, b);
        }
    }
    
    

    return 0;
}