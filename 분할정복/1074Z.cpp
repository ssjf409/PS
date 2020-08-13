#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

const int dy[4] = {0, 0, 1, 1};
const int dx[4] = {0, 1, 0, 1};

ll N, r, c;
ll cnt = 0;

ll cache[16];

ll getTime(ll y, ll x, ll N) {
    if(N == 0 && y == r && x == c) {
        cout << cnt++;
        return 1;
    }
    if(N == 0) {
        cnt++;
        return 1;
    }
    
    ll& ret = cache[N];
    if(!(y <= r && r < y + pow(2, N) && x <= c && c < x + pow(2, N)) && ret != -1) {
        cnt += ret;
        return ret;
    }

    ret = 0;
    ll half = pow(2, N - 1);
    for(int dir = 0; dir < 4; dir++) {
        ll ny = y + dy[dir] * half;
        ll nx = x + dx[dir] * half;
        ret += getTime(ny, nx, N - 1);
    }

    return ret;
}


int main() {
    cin >> N >> r >> c;
    memset(cache, -1, sizeof(cache));
    ll temp = getTime(0, 0, N);

    

    return 0;
}