#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;


// 정점의 개수
int N, M;
// 그래프의 인접 리스트, (연결된 정점 번호, 간선 가중치)쌍을 담는다.
// 시작점을 제외한 모든 정점까지의 거리 상한을 INF로 초기화한다.
vector<vector<pair<int, int>>> vertex;
vector<int> dist;

// 음수 사이클이 있을 경우 텅 빈 배열을 반환한다.
void bellmanFord(int start) {
	dist[start] = 0;
	bool updated;
	// V번 순회한다.
	for (int iter = 0; iter < N; ++iter) {
		updated = false;
        // 모든 간선을 살펴본다.
		for (int here = 0; here < N; ++here) {
			for (int i = 0; i < vertex[here].size(); ++i) {
				int there = vertex[here][i].first;
				int cost = vertex[here][i].second;
				//(here, there)간선을 따라 완화를 시도한다.
				if (dist[there] > dist[here] + cost) {
					//성공
					dist[there] = dist[here] + cost;
					updated = true;
				}
			}
		}
		// 모든 간선에 대해 완화가 실패했을 경우 V-1번도 수행할 필요 없이 곧장 종료한다.
        // 확인 필요(벨만-포드 문제에서 이 부분에서 오류)
		if (!updated) break;
	}
	// V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
	if (updated) dist.clear();
    // return dist;
}

int main() {
    int A, B, C;
    cin >> N >> M;

    vertex.assign(N + 1, vector<pair<int, int>>());
    dist.assign(N + 1, INF);

    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        vertex[A].push_back({B, C});
    }

    bellmanFord(1);
    
    
    for(int i = 2; i < dist.size(); i++) {
        if(dist[i] == 0) {
            cout << -1;
            return 0;
        }
    }
    
    for(int i = 2; i < dist.size(); i++) {
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }


    return 0;
}