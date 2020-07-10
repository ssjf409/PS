#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
vector<pair<int, pair<int, int>>> adj;
vector<int> parents;
vector<pair<long long, pair<int, int>>> edge; 

inline long long getDist(int a, int b) {
    return min(min(abs((long long)adj[a].first - adj[b].first), abs((long long)adj[a].second.first - adj[b].second.first)), abs((long long)adj[a].second.second - adj[b].second.second)));
}

int main() {
    cin >> N;
    
    adj.assign(N, pair<int, pair<int, int>>());
    parents.assign(N, 0);
    for(int i = 0; i < N; i++) {
        parents[i] = i;
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            edge.push_back({getDist(i, j), {i, j}});
        }
    }

    sort(edge.begin(), edge.end());

    



    return 0;
}