#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cache;

int tiling(int index) {
    if(n - 1 == index) return 1;
    if(n - 2 == index) return 2;

    int& ret = cache[index];
    if(ret != -1) return ret;

    ret = (tiling(index + 1) + tiling(index + 2)) % 10007;

    return ret;
}

int main() {
    cin >> n;

    cache.assign(n, -1);

    cout << tiling(0);

    return 0;
}