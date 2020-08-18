#include <iostream>
#include <vector>
#define MAX 1000000000

using namespace std;
typedef long long ll;

int N, M;
vector<int> K;

inline ll getWithdrawCnt(ll mid) {
    ll cnt = 1;
    int temp = mid;

    for(const auto money : K) {
        if(temp - money < 0) {
            cnt++;
            temp = mid - money;
        } else {
            temp -= money;
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;

    K.resize(N);

    ll low = 0, high = MAX;
    for(int i = 0; i < N; i++) {
        cin >> K[i];
        if(K[i] > low) {
            low = K[i];
        }
    }

    ll mid, result;

    while(low < high) {
        mid = (low + high) / 2;

        ll withdrawCnt = getWithdrawCnt(mid);

        if(withdrawCnt <= M) {
            high = mid;
            result = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << result;


    return 0;
}