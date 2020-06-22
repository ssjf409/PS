#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

typedef long long ll;

using namespace std;

int N, K;
vector<string> num;
vector<int> particle;
vector<int> len;
int pw[55];


ll cache[1 << 15][101];

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}


ll getHitCnt(int visited, int remain) {
    if(visited + 1 == (1 << N)) {
        if(remain == 0) {
            return  1;
        }
        else return 0;
    }

    ll& ret = cache[visited][remain];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < N; i++) {
        if(visited & (1 << i)) continue;
        int temp = (remain * pw[len[i]] + particle[i]) % K;
        ret += getHitCnt(visited | (1 << i), temp);
    }

    return ret;

}



int main() {
    cin >> N;
    num.assign(N, "");
    particle.assign(N, 0);
    len.assign(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }

    cin >> K;

    for(int i = 0; i < N; i++) {
        int temp = 0;
        len[i] = num[i].size();

        for(int j = 0; j < num[i].size(); j++) {
            temp *= 10;
            temp = (temp + (num[i][j] - '0')) % K;
        }

        particle[i] = temp;
    }

    pw[0] = 1 % K;
    for(int i = 1; i < 55; i++) {
        pw[i] = (pw[i - 1] * 10) % K;
    }



    memset(cache, -1, sizeof(cache));

    ll p = getHitCnt(0, 0);
    ll q = 1;
    if(p == 0) {
        cout << "0/1";
    } else {
        for(int i = 1 ; i <= N; i++) {
            q *= i;
        }
        ll g = gcd(p, q);

        p /= g;
        q /= g;
        cout << p << '/' << q;
    }
    
    


    return 0;
}