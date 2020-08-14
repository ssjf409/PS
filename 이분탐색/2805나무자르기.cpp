#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

inline ll getLength(const vector<ll>& tree, ll mid) {
    ll ret = 0;
    for(const auto& el : tree) {
        if(el > mid) {
            ret += el - mid;
        }
    }


    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll N, M;
    cin >> N >> M;

    vector<ll> tree(N);

    for(int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    ll low = 0, high = 2000000000;
    ll mid;

    while(low <= high) {
        mid = (low + high) / 2;
        
        ll len = getLength(tree, mid);

        if(len >= M) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high;

    

    return 0;
}