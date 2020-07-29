#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<bool> pluged(K + 1, false);
    vector<int> schedule(K, 0);

    int cnt = 0;

    for(int i = 0; i < K; i++) {
        cin >> schedule[i];
    }
    int changeCnt = 0;

    for(int i = 0; i < K; i++) {
        int cur = schedule[i];
        if(cnt == N) {
            if(!pluged[cur]) {

                vector<int> index(K + 1, INF);
                for(int j = i; j < K; j++) {
                    int n = schedule[j];
                    if(index[n] > j) index[n] = j;
                }
                
                int idx = 0;
                for(int j = 1; j <= K; j++) {
                    if(pluged[j]) {
                        if(index[pluged[j]] > idx) idx = index[pluged[j]];
                    }
                }
                pluged[idx] = false;
                pluged[cur] = true;
                changeCnt++;

            }
        } else {
            if(!pluged[cur]) {
                pluged[cur] = true;
                cnt++;
            }
        }
    }

    cout << changeCnt;


    return 0;
}