#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int P, Q;
map<ll, ll> m;

ll getValue(ll N) {
    if(N == 0) return 1;
    if(m[N] != 0) return m[N];


    m[N] = getValue(N / P) + getValue(N / Q);
    return m[N];
}


int main() {
    ll N;
    cin >> N >> P >> Q;


    cout << getValue(N);

    return 0;
}