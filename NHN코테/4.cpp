#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, G, M;
vector<pair<int, int>> stations;


int cache[10001][101];

int getMinfilling(int pos, int gas) {
    if(gas < 0) return INF;
    if(pos == stations.size() - 1) {
        if(N - stations[pos].first > gas) {
            return 1;
        } else {
            return 0;
        }
    }

    int& ret = cache[pos][gas];
    if(ret != -1) return ret;

    ret = INF;

    int dist = stations[pos + 1].first - stations[pos].first;
    return min(min(ret, getMinfilling(pos + 1, gas - dist + stations[pos].second) + 1), getMinfilling(pos + 1, gas - dist));
}

int main() {
    cin >> N >> G >> M;

    memset(cache, -1, sizeof(cache));

    // pos, 주유량
    stations.assign(N, pair<int, int>());

    for(int i = 0; i < M; i++) {
        cin >> stations[i].first;
    }

    for(int i = 0; i < M; i++) {
        cin >> stations[i].second;
    }

    int temp = getMinfilling(1, G - stations[0].first);
    if(temp == INF) {
        cout << -1 << endl;
    } else {
        cout << temp << endl;;
    }

	return 0;
}