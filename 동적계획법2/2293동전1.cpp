#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;

vector<int> coins;

int cache[101][10001];


int getCnt(int previous, int value) {
    if(value > k) return 0;
    if(value == k) return 1;

    int& ret = cache[previous][value];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = previous; i < coins.size(); i++) {
        ret += getCnt(i, value + coins[i]);
    }

    return ret;
}


int main() {
    cin >> n >> k;
    
    coins.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    memset(cache, -1, sizeof(cache));

    cout << getCnt(0, 0);


    return 0;
}