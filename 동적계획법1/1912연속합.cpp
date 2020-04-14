#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100000
#define INF 987654312

using namespace std;

int n;
int max_ = -INF;
vector<int> arr;

vector<int> cache;

int getSeqSum(int start) {
    if(start == n) return -INF;

    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = arr[start];

    ret = max(ret, ret + getSeqSum(start + 1));
    if(ret > max_) max_ = ret;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    arr.assign(n, -1);


    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cache.assign(n, -1);
    // memset(cache, -1, sizeof(cache));

    getSeqSum(0);
    cout << max_;

    return 0;
}