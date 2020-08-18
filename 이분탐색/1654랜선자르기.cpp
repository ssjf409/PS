#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int K, N;
vector<ll> cable;

int main() {
    cin >> K >> N;
    cable.resize(K);

    ll low = 0, high = 0;
    for(int i = 0; i < K; i++) {
        cin >> cable[i];
        if(cable[i] > high) {
            high = cable[i];
        }
    }

    ll mid, result = 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(mid == 0) {
            break;
        }
        ll cableNum = 0;
        for(int i = 0; i < K; i++) {
            cableNum += cable[i] / mid;
        }

        if(cableNum >= N) {
            low = mid + 1;
            result = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << result;

    return 0;
}