#include <iostream>

using namespace std;

int G, P;

int parent[100001];
int gate[100001];

int findParent(int a) {
    if(parent[a] == a) return a;
 
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    parent[a] = b;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);


    int cnt = 0;


    cin >> G >> P;
    for(int i = 1; i <= G; i++) {
        parent[i] = i;
    }

    for(int i = 1; i <= P; i++) {
        cin >> gate[i];
    }

    int temp;
    for(int i = 1; i <= P; i++) {
        temp = findParent(gate[i]);
        if(temp == 0) break;

        unionParent(temp, temp - 1);
        cnt++;
    }

    cout << cnt;

    return 0;
}