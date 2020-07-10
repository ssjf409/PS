#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M;

vector<pair<int, int>> vertex;
vector<int> parents;
vector<pair<double, pair<int, int>>> edge;


inline double getDist(int a, int b) {
    return sqrt(powl(vertex[a].first - vertex[b].first, 2) + powl(vertex[a].second - vertex[b].second, 2));
}

int findParent(int a) {
    if(a == parents[a]) return a;
    return parents[a] = findParent(parents[a]);
}

bool unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a == b) return false;
    else if(a > b) parents[a] = b;
    else parents[b] = a;
    return true;
}

int main() {
    cin >> N >> M;

    int cnt = 0;
    double sum = 0.0;

    vertex.assign(N + 1, pair<int, int>());
    parents.assign(N + 1, 0);

    for(int i = 0; i <= N; i++) {
        parents[i] = i;
    }

    for(int i = 1; i <= N; i++) {
        cin >> vertex[i].first >> vertex[i].second;
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            edge.push_back({getDist(i, j), {i, j}});
        }
    }

    sort(edge.begin(), edge.end());

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        if(unionParent(a, b)) {
            cnt++;
        }
    }

    for(int i = 0; i < edge.size() && cnt != N - 1; i++) {
        if(unionParent(edge[i].second.first, edge[i].second.second)) {
            cnt++;
            sum += edge[i].first;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << sum;

    return 0;
}