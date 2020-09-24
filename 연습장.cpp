#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;


// 정점의 개수
int N, M;
// 그래프의 인접 리스트, (연결된 정점 번호, 간선 가중치)쌍을 담는다.
// 시작점을 제외한 모든 정점까지의 거리 상한을 INF로 초기화한다.
vector<vector<pair<int, int>>> adj;
vector<long long> dist;

// 음수 사이클이 있을 경우 텅 빈 배열을 반환한다.
bool bellmanFord(int start) {
    dist.assign(N + 1, INF);
	dist[start] = 0;
    
    // 모든 간선을 살펴본다.
    for (int i = 1; i < N; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            int next = adj[i][j].first;
            int nextDist = adj[i][j].second + dist[i];
            if(dist[i] == INF) continue;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
            }
        }
    }

    // 음의 사이클이 존재하는 경우 false 반환
    for(int i = 0; i < adj[N].size(); i++) {
        int next = adj[N][i].first;
        int nextDist = adj[N][i].second + dist[N];
        if(dist[N] == INF) continue;
        if (dist[next] > nextDist) {
            return false;
        }
    }

    return true;
}

int main() {
    int A, B, C;
    cin >> N >> M;

    adj.assign(N + 1, vector<pair<int, int>>());

    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
    }

    if(bellmanFord(1)) {
        
        for(int i = 2; i <= N; i++) {
            if(dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }

    } else {
        cout << -1;
    }


    return 0;
}