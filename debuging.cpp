#include <iostream>
#include <cstring>
#define MOD 1000000007
#define MAX 1000000

using namespace std;

typedef long long ll;

ll cache[MAX + 1];

ll facto(ll n) {
    if(n == 1 || n == 0) return 1;
    ll& ret = cache[n];
    if(ret != -1) return ret;

    return ret = (n * facto(n - 1)) % MOD;
}

ll getPath(ll dy, ll dx) {
    cout << "============\n";
    cout << facto(dy + dx) << endl;
    cout << facto(dy) << endl;
    cout << facto(dx) << endl;
    return (facto(dy + dx) * 10 / facto(dy) / facto(dx) / 10) % MOD;
}


int main() {
	ll N, M;
	ll acorny, acornx;
	ll trapy, trapx;
	cin >> N >> M;
	cin >> acorny >> acornx;
	cin >> trapy >> trapx;

    memset(cache, -1, sizeof(cache));
    
    ll start2acorn = getPath(acorny, acornx);
    ll acorn2goal = getPath((N - acorny), (M - acornx));
    ll totalPath = start2acorn * acorn2goal % MOD;
    cout << start2acorn << endl;
    
    if(trapy <= acorny && trapx <= acornx) {
        ll start2trap = getPath(trapy, trapx);
        ll trap2acorn = getPath((acorny - trapy), (acornx - trapx));
        ll trapedPath = (start2trap * trap2acorn) % MOD * acorn2goal % MOD;
        totalPath -= trapedPath;
    } else if(trapy >= acorny && trapx >= acornx) {
        ll acorn2trap = getPath((trapy - acorny), (trapx - acornx));
        ll trap2goal = getPath((N - trapy), (M - trapx));

        ll trapedPath = (start2acorn * acorn2trap) % MOD * trap2goal % MOD;
        totalPath -= trapedPath;

    }

    
    // ll start2acorn = acorny * acornx % MOD;
    // ll acorn2goal = (N - acorny) * (M - acornx) % MOD;
    // ll totalPath = start2acorn * acorn2goal % MOD;
    
    // if(trapy <= acorny && trapx <= acornx) {
    //     ll start2trap = trapy * trapx % MOD;
    //     ll trap2acorn = (acorny - trapy) * (acornx - trapx) % MOD;
    //     ll trapedPath = (start2trap * trap2acorn) % MOD * acorn2goal % MOD;
    //     totalPath -= trapedPath;
    // } else if(trapy >= acorny && trapx >= acornx) {
    //     ll acorn2trap = (trapy - acorny) * (trapx - acornx) % MOD;
    //     ll trap2goal = (N - trapy) * (M - trapx) % MOD;

    //     ll trapedPath = (start2acorn * acorn2trap) % MOD * trap2goal % MOD;
    //     totalPath -= trapedPath;

    // }

    cout << totalPath;
	
	
	return 0;
}