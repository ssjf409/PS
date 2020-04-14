#include <iostream>
#define INF 987654321

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;
    int sum[N + 1];
    int tsum = 0;
    int cnt = 0;
    int min = INF;

    int input;
    sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> input;
        sum[i] = input + sum[i - 1];
    }

    // for(const auto& ele : sum) {
    //     cout << ele << ' ';
    // }

    int lo = 0;
    int hi = 0;

    while(1) {
        tsum = sum[hi] - sum[lo];
        if(tsum >= S) {
            if(hi - lo < min) min = hi - lo;
            lo++;
        } else if(hi == N) break;
        else hi++;

    }

    if(min == INF) cout << 0;
    else cout << min;

    return 0;
}